#include <iostream>

int main(){

  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int lenVec, *vecColunas, D1 = 0, D2 = 0, num, maxSum = 0, sumCurrentLine;
  bool result = true;

  std::cin >> lenVec;

  vecColunas = new int[lenVec]{0};

  for(int i = 0; i < lenVec; i++){

    sumCurrentLine = 0;

    for(int j = 0; j < lenVec; j++){

      std::cin >> num;

      vecColunas[j] += num;
      sumCurrentLine += num;

      if(i == 0)
        maxSum += num;

      if(i == j)
        D1 += num;

      if((i + j + 1) == lenVec)
        D2 += num;

    }

    if(sumCurrentLine != maxSum)
      result = false;
    
  }

  if(D1 != maxSum || D2 != maxSum)
    result = false;

  for(int i = 0; i < lenVec; i++){

    if(vecColunas[i] != maxSum){

      result = false;
      break;

    }
    
  }

  if(result)
    std::cout << maxSum << std::endl;
  
  else
    std::cout << -1 << std::endl;

  return 0;
}
