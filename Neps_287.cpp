#include <iostream>

void mergeSort(long* vec, long indexLeft, long indexRight);

int main(){

  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  long totalVec, *vec;

  std::cin >> totalVec;
  
  vec = new long[totalVec];

  for(long i = 0; i < totalVec; i++)
    std::cin >> vec[i];

  mergeSort(vec, 0, (totalVec - 1));

  for(long i = (totalVec - 1); i >= 0; i--){

    if(i < (totalVec - 1))
      std::cout << ' ';

    std::cout << vec[i];

  }

  std::cout << std::endl;

  return 0;
}

void mergeFcn(long* vec, long indexLeft, long indexMiddle, long indexRight){

  long* vecMudancas = new long[indexRight - indexLeft + 1], changeRight = indexMiddle + 1, changeLeft = indexLeft;

  for(long i = 0; i < (indexRight - indexLeft + 1); i++){

    if(changeLeft > indexMiddle || (changeRight <= indexRight && vec[changeRight] <= vec[changeLeft])){

      vecMudancas[i] = vec[changeRight];
      changeRight++;

    }

    else if(changeRight > indexRight || (changeLeft <= (indexMiddle + 1) && vec[changeLeft] <= vec[changeRight])){

      vecMudancas[i] = vec[changeLeft];
      changeLeft++;

    }

  }

  for(long i = 0, j = indexLeft; j <= indexRight; i++, j++)
    vec[j] = vecMudancas[i];

}

void mergeSort(long* vec, long indexLeft, long indexRight){

  long middle = (indexLeft + indexRight) / 2;

  if(indexLeft < indexRight){

    mergeSort(vec, indexLeft, middle);
    mergeSort(vec, middle + 1, indexRight);

    mergeFcn(vec, indexLeft, middle, indexRight);

  }

}
