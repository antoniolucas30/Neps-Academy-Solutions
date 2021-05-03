#include <iostream>

int main(){

  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  unsigned long long num;

  std::cin >> num;

  for(int i = num - 1; i > 0; i--)
    num *= i;

  if(num == 0)
    num = 1;

  std::cout << num << '\n';

  return 0;
}
