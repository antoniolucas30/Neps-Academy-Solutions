#include <iostream>

int main(){

  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int x, y;

  std::cin >> x >> y;

  if(x == 0 || y == 0)
    std::cout << "eixos\n";

  else if(x > 0 && y > 0)
    std::cout << "Q1\n";

  else if(x < 0 && y > 0)
    std::cout << "Q2\n";

  else if(x < 0 && y < 0)
    std::cout << "Q3\n";

  else if(x > 0 && y < 0)
    std::cout << "Q4\n";

  return 0;
}
