#include <iostream>

int main(){

  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int vec[3] = {0}, num;

  for(int i = 0; i < 3; i++){

    for(int j = 0; j < 3; j++){

      std::cin >> num;
      vec[j] += num;

    }

  }

  for(int i = 0; i < 3; i++)
    std::cout << "Coluna " << i << ": " << vec[i] << '\n';

  return 0;
}
