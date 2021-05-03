#include <iostream>

int** DP;

int LCS(int* vec1, int* vec2, int indexVec1, int indexVec2);

int main(){

  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int len1, len2, *vec1, *vec2, finalResult;

  std::cin >> len1 >> len2;

  vec1 = new int[len1], vec2 = new int[len2];
  DP = new int*[len1];

  for(int i = 0; i < len1; i++){
    
    DP[i] = new int[len2];
    
    for(int j = 0; j < len2; j++)
      DP[i][j] = -1;

    std::cin >> vec1[i];

  }

  for(int i = 0; i < len2; i++)
    std::cin >> vec2[i];

  finalResult = LCS(vec1, vec2, (len1 - 1), (len2 - 1));

  std::cout << len1 - finalResult << ' ' << len2 - finalResult << std::endl;  

  return 0;
}

int LCS(int* vec1, int* vec2, int indexVec1, int indexVec2){

  int temp1, temp2, result;

  if(indexVec1 < 0 || indexVec2 < 0)
    return 0;

  if(DP[indexVec1][indexVec2] != -1)
    return DP[indexVec1][indexVec2];

  if(vec1[indexVec1] == vec2[indexVec2])
    result = 1 + LCS(vec1, vec2, indexVec1 - 1, indexVec2 -1);

  else{

    temp1 = LCS(vec1, vec2, indexVec1 - 1, indexVec2);
    temp2 = LCS(vec1, vec2, indexVec1, indexVec2 - 1);

    result = std::max(temp1, temp2);

  }

  return DP[indexVec1][indexVec2] = result;

}
