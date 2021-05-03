#include <iostream>

int matrix[101][101], lenMatrix, sum;

int main(){

  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  std::cin >> lenMatrix;

  for(int i = 0; i < lenMatrix; i++){

    for(int j = 0; j < lenMatrix; j++)
      std::cin >> matrix[i][j];

  }

  for(int i = 1; i < lenMatrix; i++){

    for(int j = 1; j < lenMatrix; j++){

      sum = matrix[i - 1][j] + matrix[i][j - 1] + matrix[i - 1][j - 1];

      if(sum <= 1)
        matrix[i][j] = 1;

      else
        matrix[i][j] = 0;

    }

  }

  std::cout << matrix[lenMatrix - 1][lenMatrix - 1] << '\n';

  return 0;
}
