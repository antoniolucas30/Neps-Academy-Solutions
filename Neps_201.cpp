#include <iostream>

int main(){

  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int num, r1 = 0, r2 = 0;

  for(int i = 0; i < 3; i++){

    for(int j = 0; j < 3; j++){
    
      std::cin >> num;

      if(i == j)
        r1 += num;

      if((i + j) == 2)
        r2 += num;

    }

  }

  std::cout << "Diagonal principal: " << r1 << "\nDiagonal secundaria: " << r2 << '\n';

  return 0;
}
