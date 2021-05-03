#include <iostream>

struct Positions{

  long long posX, posY;

};

long long mergeSort(Positions* vecPositions, long long leftIndex, long long rightIndex);

int main(){

  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  long long totalVec, result = 0;
  Positions* vecPositions;

  std::cin >> totalVec;

  vecPositions = new Positions[totalVec];

  for(long long i = totalVec - 1; i >= 0; i--){
    
    std::cin >> vecPositions[i].posX >> vecPositions[i].posY;
    
  }

  result = mergeSort(vecPositions, 0, (totalVec - 1));

  std::cout << result << std::endl;


  return 0;
}

long long mergeFcn(Positions* vecPositions, long long leftIndex, long long middleIndex, long long rightIndex){

  Positions *temporaryArray = new Positions[rightIndex - leftIndex + 1];
  long long changeLeft = leftIndex, changeRight = middleIndex + 1, indexTemporary = 0;
  long long distRight, distLeft, countInversions = 0;

  while((changeLeft <= middleIndex) && (changeRight <= rightIndex)){

    distRight = (vecPositions[changeRight].posX * vecPositions[changeRight].posX) + (vecPositions[changeRight].posY * vecPositions[changeRight].posY);
    distLeft = (vecPositions[changeLeft].posX * vecPositions[changeLeft].posX) + (vecPositions[changeLeft].posY * vecPositions[changeLeft].posY);

    if(distLeft < distRight)
      temporaryArray[indexTemporary++] = vecPositions[changeLeft++];

    else{

      temporaryArray[indexTemporary++] = vecPositions[changeRight++];
      countInversions += (middleIndex - changeLeft) + 1;
    }

  }

  while((changeLeft <= middleIndex))
    temporaryArray[indexTemporary++] = vecPositions[changeLeft++];

  while(changeRight <= rightIndex)
    temporaryArray[indexTemporary++] = vecPositions[changeRight++];

  for(long long i = 0, j = leftIndex; j <= rightIndex; i++, j++)
    vecPositions[j] = temporaryArray[i];

  delete[] temporaryArray;

  return countInversions;

}

long long mergeSort(Positions* vecPositions, long long leftIndex, long long rightIndex){

  long long middle;
  long long countInversions = 0;

  if(leftIndex < rightIndex){

    middle = (leftIndex + rightIndex) / 2;

    countInversions += mergeSort(vecPositions, leftIndex, middle);
    countInversions += mergeSort(vecPositions, middle + 1, rightIndex);

    countInversions += mergeFcn(vecPositions, leftIndex, middle, rightIndex);

  }

  return countInversions;

}
