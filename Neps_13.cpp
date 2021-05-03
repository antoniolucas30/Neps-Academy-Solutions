#include <iostream>

int main(){

  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int A, B;
  std::string result = "NS";

  std::cin >> A >> B;

  std::cout << result[(A + B) <= 50] << std::endl;

  return 0;
}
