#include <iostream>
#include <utility>

long long Knapsack(std::pair <long, long>* vecMeat, long long** matrix, int currentIndex, int currentCapacity, int totalLen);

int main(){

  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  long long** matrix;
  int totalGrams, totalLen;
  std::pair <long, long>* vecMeat;

  std::cin >> totalGrams >> totalLen;

  vecMeat = new std::pair <long, long>[totalLen];
  matrix = new long long*[totalLen + 1];

  for(int i = 0; i < (totalLen + 1); i++){
  
    matrix[i] = new long long[totalGrams + 1];

    if(i != totalLen)
      std::cin >> vecMeat[i].first >> vecMeat[i].second;

    for(int j = 0; j < (totalGrams + 1); j++)
      matrix[i][j] = -1;

  }

  std::cout << Knapsack(vecMeat, matrix, 0, totalGrams, totalLen) << std::endl;

  return 0;
}

long long Knapsack(std::pair <long, long>* vecMeat, long long** matrix, int currentIndex, int currentCapacity, int totalLen){

  long long temporaryPut, temporaryDontPut;

  if(matrix[currentIndex][currentCapacity] != -1)
    return matrix[currentIndex][currentCapacity];

  if(currentIndex == totalLen || currentCapacity == 0)
    return matrix[currentIndex][currentCapacity] = 0;

  temporaryDontPut = Knapsack(vecMeat, matrix, currentIndex + 1, currentCapacity, totalLen);

  if(vecMeat[currentIndex].first <= currentCapacity){

    temporaryPut = vecMeat[currentIndex].second + Knapsack(vecMeat, matrix, currentIndex + 1, currentCapacity - vecMeat[currentIndex].first, totalLen);

    return matrix[currentIndex][currentCapacity] = std::max(temporaryPut, temporaryDontPut);

  }

  return matrix[currentIndex][currentCapacity] = temporaryDontPut;

}
