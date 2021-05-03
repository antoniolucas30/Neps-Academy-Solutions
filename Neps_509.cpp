#include <iostream>

int solve(long finalValue, long* vec, long* DP, long currentIndex, long totalLen);

int main(){

  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  long finalValue, lenVec, *vec, *DP;
  std::string ans = "NS";

  std::cin >> finalValue >> lenVec;

  vec = new long[lenVec], DP = new long[finalValue + 1];

  for(long i = 0; i < finalValue + 1; i++)
    DP[i] = -1;

  for(long i = 0; i < lenVec; i++)
    std::cin >> vec[i];

  std::cout << ans[solve(finalValue, vec, DP, 0, lenVec)] << '\n';

  return 0;
}

int solve(long finalValue, long* vec, long* DP, long currentIndex, long totalLen){

  long lastNum;

  if(finalValue == 0)
    std::cout << "AAAAAAAAAAAAAAAAAAAAAAAn\n";

  if(finalValue == 0)
    return 1;

  if(finalValue < 0)
    return 0;

  //if(DP[finalValue] >= 0)
    //return DP[finalValue];

  for(long i = 0; i < totalLen; i++){
    
    lastNum = vec[i];

    if(lastNum != 0){

      vec[i] = 0;

      if(solve(finalValue - lastNum, vec, DP, currentIndex, totalLen))
        return DP[finalValue - vec[i]] = 1;

      vec[i] = lastNum;

    }
  }

  return DP[finalValue] = 0;

}
