#include <iostream>

int main(){

  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int num, result = 0;

  for(int i = 0; i < 3; i++){

    std::cin >> num;

    if((num % 2) == 0)
      result++;

    else if((num % 5) == 0)
      result++;

  }

  std::cout << result << '\n';

  return 0;
}
