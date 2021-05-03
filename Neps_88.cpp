#include <iostream>
#include <algorithm>
#include <utility>

bool Compare(std::pair <bool, char> n1, std::pair <bool, char> n2);

int main(){

  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  std::pair <bool, char>* Vec = new std::pair <bool, char>[3];
  char whatChar = 'A';
  bool finger;

  for(int i = 0; i < 3; i++){

    std::cin >> finger;

    Vec[i] = std::make_pair(finger, whatChar);
    whatChar++;

  }

  std::sort(Vec, Vec + 3, Compare);

  if(Vec[0].first != Vec[1].first)
    std::cout << Vec[0].second << '\n';

  else if(Vec[2].first != Vec[1].first)
    std::cout << Vec[2].second << '\n';

  else
    std::cout << "*\n";
  
  return 0;
}

bool Compare(std::pair <bool, char> n1, std::pair <bool, char> n2){

  return n1.first < n2.first;

}
