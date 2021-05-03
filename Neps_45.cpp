#include <iostream>
#include <algorithm>

int main(){

  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int num, matrixComponent, **matrix;
  long *sumI, *sumJ, result = -1;

  std::cin >> num;

  matrix = new int*[num];
  sumI = new long[num]{0};
  sumJ = new long[num]{0};

  for(int i = 0; i < num; i++){

    matrix[i] = new int[num];

    for(int j = 0; j < num; j++){

      std::cin >> matrixComponent;

      matrix[i][j] = matrixComponent;

      sumI[i] += matrixComponent;
      sumJ[j] += matrixComponent;

    }

  }

  for(int i = 0; i < num; i++){

    for(int j = 0; j < num; j++){

      if((sumI[i] - matrix[i][j]) + (sumJ[j] - matrix[i][j]) > result)
        result = (sumI[i] - matrix[i][j]) + (sumJ[j] - matrix[i][j]);

    }

  }
  
  std::cout << result << std::endl;

  return 0;
}
