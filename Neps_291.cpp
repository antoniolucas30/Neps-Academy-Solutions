#include <iostream>
#include <utility>

long long Knapsack(std::pair <int, int>* vecPhrases, long long** matrix, int currentIndex, int currentCapacity, int totalLen);

int main(){

  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int cardLen, phrasesLen, ans = 0;
  long long** matrix;
  std::pair <int, int>* vecPhrases;

  while(std::cin >> cardLen >> phrasesLen && cardLen != 0 && phrasesLen != 0){

    vecPhrases = new std::pair <int, int>[phrasesLen];
    matrix = new long long*[phrasesLen + 1];

    for(int i = 0; i < phrasesLen + 1; i++){

      matrix[i] = new long long[cardLen + 1];

      for(int j = 0; j < cardLen + 1; j++)
        matrix[i][j] = -1;

      if(i != phrasesLen)
        std::cin >> vecPhrases[i].first >> vecPhrases[i].second;

    }

    std::cout << "Teste " << ++ans << '\n' << Knapsack(vecPhrases, matrix, 0, cardLen, phrasesLen) << "\n\n" << std::flush;

    for(int i = 0; i < phrasesLen + 1; i++)
      delete[] matrix[i];

    delete[] matrix;
    delete[] vecPhrases;

  }

  return 0;
}

long long Knapsack(std::pair <int, int>* vecPhrases, long long** matrix, int currentIndex, int currentCapacity, int totalLen){

  long long temporaryPut, temporaryDontPut;

  if(matrix[currentIndex][currentCapacity] != -1)
    return matrix[currentIndex][currentCapacity];

  if(currentIndex == totalLen || currentCapacity == 0)
    return matrix[currentIndex][currentCapacity] = 0;

  temporaryDontPut = Knapsack(vecPhrases, matrix, currentIndex + 1, currentCapacity, totalLen);

  if(vecPhrases[currentIndex].first <= currentCapacity){

    temporaryPut = vecPhrases[currentIndex].second + Knapsack(vecPhrases, matrix, currentIndex + 1, currentCapacity - vecPhrases[currentIndex].first, totalLen);

    return matrix[currentIndex][currentCapacity] = std::max(temporaryPut, temporaryDontPut);

  }

  return matrix[currentIndex][currentCapacity] = temporaryDontPut;

}
