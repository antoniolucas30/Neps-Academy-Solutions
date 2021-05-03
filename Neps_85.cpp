#include <iostream>
#include <iomanip>

int main(){

  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  double n1, n2;

  std::cin >> n1 >> n2;

  std::cout << std::fixed << std::setprecision(2) << n1/n2 << '\n';

  return 0;
}
