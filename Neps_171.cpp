#include <iostream>
#include <cmath>
#include <iomanip>

int main(){

  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  double x, y;

  std::cin >> x >> y;

  std::cout << std::fixed << std::setprecision(4) << std::pow(x, y) << std::endl;

  return 0;
}
