#include <iostream>

int main(){

  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int tests, len, result, vecSide;
  char side;

  std::cin >> tests;

    int vec[61][2] = {0};
    result = 0;

    for(int i = 0; i < tests; i++){

      std::cin >> len >> side;

      (side == 'D') ? vecSide = 1 : vecSide = 0;

      if(vec[len][!vecSide] != 0){

	result++;
	vec[len][!vecSide]--;

      }

      else
	vec[len][vecSide]++;

    }

    std::cout << result << std::endl;

  

  return 0;
}
