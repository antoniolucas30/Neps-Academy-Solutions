#include <iostream>

int main(){

  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int num;

  std::cin >> num;

  std::cout << (num * 4) << '\n';

  return 0;
}
