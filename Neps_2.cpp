#include <iostream>
#include <utility>
#include <algorithm>

bool Compare(std::pair <int, int> n1, std::pair <int, int> n2);

int main(){

  std::pair <int, int>* VecPair = new std::pair <int, int>[3];
  int time;

  for(int i = 1; i <= 3; i++){

    std::cin >> time;

    VecPair[i - 1] = std::make_pair(time, i);

  }

  std::sort(VecPair, VecPair + 3, Compare);

  for(int i = 0; i < 3; i++)
    std::cout << VecPair[i].second << '\n';

  return 0;
}

bool Compare(std::pair <int, int> n1, std::pair <int, int> n2){

  return n1.first < n2.first;

}
