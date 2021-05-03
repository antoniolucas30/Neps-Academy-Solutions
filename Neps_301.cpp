#include <iostream>

long long LCS(long long** DP, long long* vec1, long long* vec2, long long indexVec1, long long indexVec2);

int main(){
  
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  long long lenVec1, lenVec2, *vec1, *vec2, **DP;

  std::cin >> lenVec1 >> lenVec2;

  vec1 = new long long[lenVec1], vec2 = new long long[lenVec2], DP = new long long*[lenVec1];

  for(long long i = 0; i < lenVec1; i++){

    DP[i] = new long long[lenVec2];

    for(long long j = 0; j < lenVec2; j++)
      DP[i][j] = -1;

    std::cin >> vec1[i];

  }

  for(long long i = 0; i < lenVec2; i++)
    std::cin >> vec2[i];

  std::cout << LCS(DP, vec1, vec2, (lenVec1 - 1), (lenVec2 - 1)) << std::endl;

  return 0;
}

long long LCS(long long** DP, long long* vec1, long long* vec2, long long indexVec1, long long indexVec2){

  long long result, tmp1, tmp2;

  if(indexVec1 < 0 || indexVec2 < 0)
    return 0;

  if(DP[indexVec1][indexVec2] != -1)
    return DP[indexVec1][indexVec2];

  if(vec1[indexVec1] == vec2[indexVec2])
    result = 1 + LCS(DP, vec1, vec2, indexVec1 - 1, indexVec2 - 1);

  else{

    tmp1 = LCS(DP, vec1, vec2, indexVec1 - 1, indexVec2);
    tmp2 = LCS(DP, vec1, vec2, indexVec1, indexVec2 - 1);

    result = std::max(tmp1, tmp2);

  }

  DP[indexVec1][indexVec2] = result;

  return DP[indexVec1][indexVec2];

}
