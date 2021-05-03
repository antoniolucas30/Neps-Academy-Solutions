#include <iostream>

int main(){

  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n1, n2, n3, n4;

  std::cin >> n1 >> n2 >> n3 >> n4;

  std::cout << std::max(n1 * n2, n3 * n4) << '\n';

  return 0;
}
