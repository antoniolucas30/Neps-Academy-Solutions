#include <iostream>

int main(){

  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  long num;

  std::cin >> num;

  std::cout << ((num + 1) * (num + 2)) / 2 << '\n';

  return 0;
}
