#include <iostream>

int main(){

  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int matrix[3][3], biggest;

  for(int i = 0; i < 3; i++){

    for(int j = 0; j < 3; j++){

      std::cin >> matrix[i][j];

      if(i == 0 && j == 0)
        biggest = matrix[i][j];

      else if(matrix[i][j] > biggest)
        biggest = matrix[i][j];

    }

  }

  for(int i = 0; i < 3; i++){

    for(int j = 0; j < 3; j++){

      if(j != 0)
        std::cout << ' ';

      if(matrix[i][j] == biggest)
        std::cout << -1;

      else
        std::cout << matrix[i][j];

    }

    std::cout << '\n';

  }

  return 0;
}
