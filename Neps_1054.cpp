#include <iostream>

int main(){

  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  long min, max;
  double result;

  std::cin >> max >> min;

  result = max * 0.3;

  if(result >= min)
    std::cout << long(result) << '\n';

  else
    std::cout << 0 << '\n';

  return 0;
}
