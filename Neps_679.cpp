#include <iostream>

int main(){

  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  long long currentNum = 0, lastNum = 1, lastLast = 1;

  while(currentNum < 10000000000){

    currentNum = lastNum + lastLast;
    lastLast = lastNum, lastNum = currentNum;

    std::cout << currentNum << '\n';

  }

  return 0;
}
