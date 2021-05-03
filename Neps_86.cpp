#include <iostream>

int main(){

  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  double num1, num2, result;

  std::cin >> num1 >> num2;

  result = (num1 + num2) / 2.0;

  if(result >= 7.0)
    std::cout << "Aprovado" << std::endl;
  else if(result < 4.0)
    std::cout << "Reprovado" << std::endl;
  else
    std::cout << "Recuperacao" << std::endl;

  return 0;
}
