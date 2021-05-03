#include <iostream>

int main(){

  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  bool who;
  int n1, n2;

  std::cin >> who >> n1 >> n2;

  n1 += n2;

  if((n1 % 2) != 0)
    who = !who;

  std::cout << who << '\n';

  return 0;
}
