#include <iostream>

int main(){

  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n1, n2;

  std::cin >> n1 >> n2;

  std::cout << ((4 * n1) + (6 * n2)) / 10 << '\n';

  return 0;
}
