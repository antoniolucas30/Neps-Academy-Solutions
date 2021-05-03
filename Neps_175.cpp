#include <iostream>
#include <cmath>

int main(){

  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  long n1;
  bool ans = true;
  std::string result = "NS";

  std::cin >> n1;

  if(n1 == 1)
    ans = false;

  for(long i = 2; i <= std::sqrt(n1); i++){

    if((n1 % i) == 0){

      ans = false;
      break;

    }

  }

  std::cout << result[ans] << '\n';

  return 0;
}
