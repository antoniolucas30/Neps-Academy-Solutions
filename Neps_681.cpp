#include <iostream>
#include <algorithm>

int main(){

  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  long lenVec, *vec, indexI, indexJ, indexZ, vecSort[3];

  std::cin >> lenVec;

  vec = new long[lenVec];

  for(long i = 0; i < lenVec; i++)
    std::cin >> vec[i];

  std::sort(vec, vec + lenVec);

  indexZ = lenVec - 1, indexJ = lenVec - 2, indexI = lenVec - 3;

  while(1){
   
    if(indexI <= -1){

      indexJ--;
      indexI = indexJ - 1;

    }

    if(indexJ <= 0){

      indexZ--;
      indexJ = indexZ - 1;
      indexI = indexJ - 1;

    }

    if(vec[indexZ] < (vec[indexJ] + vec[indexI])){

      vecSort[0] = vec[indexZ], vecSort[1] = vec[indexJ], vecSort[2] = vec[indexI];

      std::sort(vecSort, vecSort + 3);

      std::cout << vecSort[0] << ' ' << vecSort[1] << ' ' << vecSort[2] << '\n';

      break;
    }

    else
      indexI--;

  }

  return 0;
}
