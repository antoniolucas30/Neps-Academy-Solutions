#include <iostream>

int main(){

  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int min;

  std::cin >> min;

  std::cout << min / 60 << '\n' << min % 60 << '\n';

  return 0;
}
