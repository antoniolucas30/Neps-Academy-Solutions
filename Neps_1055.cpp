#include <iostream>
#include <utility>

long long Vec[100002] = {0}; 
long currentIndex = 0;

void atualiza(long tam, long value);
long long soma(int index);

int main(){

  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  long len, K, P, lenConsulta, totalLen = 0, d1, d2;
  std::pair <long, long>* vecPair;

  std::cin >> len;

  vecPair = new std::pair<long, long>[len];

  for(long i = 0; i < len; i++){

    std::cin >> K >> P;

    vecPair[i] = std::make_pair(K, P);

    totalLen += K;

  }

  for(long i = 0; i < len; i++){

    for(long j = 0; j < vecPair[i].first; j++){

      currentIndex++;

      atualiza(totalLen, vecPair[i].second);

    }

  }

  std::cin >> lenConsulta;

  for(long i = 0; i < lenConsulta; i++){

    std::cin >> d1 >> d2;

    std::cout << soma(d2) - soma(d1 - 1) << '\n';

  }

  return 0;
}

void atualiza(long tam, long value){

  long index = currentIndex;

  while(index <= tam){

    Vec[index] += value;
    index += (index & -index);

  }

}

long long soma(int index){

  long long result = 0;

  while(index > 0){

    result += Vec[index];
    index -= (index & -index);

  }

  return result;

}
