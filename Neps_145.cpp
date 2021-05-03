#include <iostream>

int main(){

  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int num;

  std::cin >> num;

  if(num > 0)
    std::cout << "positivo" << std::endl;
  else if(num < 0)
    std::cout << "negativo" << std::endl;
  else
    std::cout << "nulo" << std::endl;

  return 0;
}
