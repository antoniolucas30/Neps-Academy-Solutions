#include <iostream>

int main(){

  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int total, n1, n2;

  std::cin >> total >> n1 >> n2;

  if(n1 >= n2)
    std::cout << n1 - n2 << '\n';

  else
    std::cout << ((total - n2) + n1) << '\n';

  return 0;
}
