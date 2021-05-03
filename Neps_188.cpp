#include <iostream>

int vec[12];

int main(){

  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int lenQueries, current, max = 0;
  bool printSpace = false;

  std::cin >> lenQueries;

  for(int i = 0; i < lenQueries; i++){

    std::cin >> current;

    vec[--current]++;

    if(vec[current] > max)
      max = vec[current];

  }

  for(int i = 0; i < 12; i++){

    if(vec[i] == max){

      if(printSpace)
        std::cout << ' ';

      printSpace = true;

      std::cout << (i + 1);

    }

  }

  std::cout << '\n';

  return 0;
}
