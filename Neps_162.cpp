#include <iostream>

int main(){

  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n1;

  std::cin >> n1;

  if(n1 <= 800)
    std::cout << "1\n";

  else if(n1 <= 1400)
    std::cout << "2\n";

  else
    std::cout << "3\n";

  return 0;
}
