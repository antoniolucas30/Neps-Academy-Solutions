#include <iostream>

int main(){

  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n1;

  std::cin >> n1;

  n1 -= 9;

  if(n1 < 0)
    n1 = 24 + n1;

  std::cout << n1 << '\n';

  return 0;
}
