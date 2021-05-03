#include <iostream>

int main(){

  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n1, result = -9999;

  for(int i = 0; i < 3; i++){

    std::cin >> n1;

    if(n1 > result)
      result = n1;

  }

  std::cout << result << '\n';

  return 0;
}
