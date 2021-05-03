#include <iostream>

long mergeSort(long* vec, long leftIndex, long rightIndex);

int main(){

  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  long totalVec, *vec;

  std::cin >> totalVec;

  vec = new long[totalVec];

  for(long i = 0; i < totalVec; i++)
    std::cin >> vec[i];

  std::cout << mergeSort(vec, 0, (totalVec - 1)) << std::endl;

  return 0;
}

long mergeFcn(long* vec, long leftIndex, long middleIndex, long rightIndex){

  long* temporaryArray = new long[rightIndex - leftIndex + 1], changeLeft = leftIndex, changeRight = middleIndex + 1, countInversions = 0, currentIndex = 0;

  while((changeLeft <= middleIndex) && (changeRight <= rightIndex)){

    if(vec[changeLeft] <= vec[changeRight])
      temporaryArray[currentIndex++] = vec[changeLeft++];

    else{

      temporaryArray[currentIndex++] = vec[changeRight++];
      countInversions += (middleIndex - changeLeft) + 1;

    }

  }

  while(changeLeft <= middleIndex)
    temporaryArray[currentIndex++] = vec[changeLeft++];

  while(changeRight <= rightIndex)
    temporaryArray[currentIndex++] = vec[changeRight++];

  for(long i = 0, j = leftIndex; j <= rightIndex; i++, j++)
    vec[j] = temporaryArray[i];

  return countInversions;

}

long mergeSort(long* vec, long leftIndex, long rightIndex){

  long middle, countInversions = 0;

  if(leftIndex < rightIndex){

    middle = (leftIndex + rightIndex) / 2;

    countInversions += mergeSort(vec, leftIndex, middle);
    countInversions += mergeSort(vec, middle + 1, rightIndex);

    countInversions += mergeFcn(vec, leftIndex, middle, rightIndex);

  }

  return countInversions;

}
