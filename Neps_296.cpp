#include <iostream>

int main(){

  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  bool* nums;
  int K, primeU;
  long N, result;

  std::cin >> N >> K;

  nums = new bool[N];
  result = N;

  for(int i = 0; i < K; i++){

    std::cin >> primeU;

    for(long j = 1; (primeU * j) <= N; j++){

      if(nums[(primeU * j)] == 0){

        nums[primeU * j] = 1;
        result--;

      }

    }

  }

  std::cout << result << std::endl;

  return 0;
}
