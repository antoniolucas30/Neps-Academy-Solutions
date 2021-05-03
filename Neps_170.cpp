#include <iostream>
#include <cmath>
#include <iomanip>

int main(){

  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int num;
  double currentNum;

  std::cin >> num;

  for(int i = 0; i < num; i++){

    std::cin >> currentNum;
    std::cout << std::fixed << std::setprecision(4) << std::sqrt(currentNum) << '\n';

  }

  std::cout << std::flush;

  return 0;
}
