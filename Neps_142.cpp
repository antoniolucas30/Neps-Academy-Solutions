#include <iostream>

int main(){

  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n1, n2;

  std::cin >> n1 >> n2;
  std::cout << (n1 * 60) + n2 << '\n';

  return 0;
}
