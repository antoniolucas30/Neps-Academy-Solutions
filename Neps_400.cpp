#include <iostream>
#include <algorithm>

int main(){

  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int vec[10];

  for(int i = 0; i < 10; i++)
    std::cin >> vec[i];

  std::sort(vec, vec + 10);

  for(int i = 0; i < 10; i++){

    if(i != 0)
      std::cout << ' ';

    std::cout << vec[i];

  }

  std::cout << '\n';

  for(int i = 9; i >= 0; i--){

    if(i != 9)
      std::cout << ' ';

    std::cout << vec[i];

  }

  std::cout << '\n';

  return 0;
}
