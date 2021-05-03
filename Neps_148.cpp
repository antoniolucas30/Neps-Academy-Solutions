#include <iostream>

int main(){

  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  std::string result[2] = {"Cino", "Bino"};
  int A, B;

  std::cin >> A >> B;

  std::cout << result[(A+B) % 2 == 0] << std::endl;

  return 0;
}
