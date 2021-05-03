#include <iostream>

int main(){

  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  std::string num, result = "NS";
  long sum = 0, lenStr;

  std::cin >> num;

  lenStr = num.length();

  for(int i = 0; i < lenStr; i++){

    if((i % 2) == 0)
      sum -= num[i] - '0';

    else
      sum += num[i] - '0';

  }

  std::cout << result[(sum == 0 || !(sum % 11))] << '\n';

  return 0;
}
