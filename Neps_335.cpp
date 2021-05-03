#include <iostream>
#include <cmath>

int main(){

  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int vec[4];

  for(int i = 0; i < 4; i++)
    std::cin >> vec[i];

  std::cout << std::abs(vec[0] - vec[2]) + std::abs(vec[1] - vec[3]) << '\n';

  return 0;
}
