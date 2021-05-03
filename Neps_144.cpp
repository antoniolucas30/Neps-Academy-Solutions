#include <iostream>
#include <iomanip>

#define PI 3.1416

int main(){

  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n1;

  std::cin >> n1;

  std::cout << std::fixed << std::setprecision(2) << (n1 * n1) * PI << '\n';

  return 0;
}
