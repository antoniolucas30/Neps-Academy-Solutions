#include <iostream>

int main(){

  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  std::string num, ans = "NS";
  long len, lastDigit, sum = 0;

  std::cin >> num;
  len = num.length();
  lastDigit = num[len - 1] - '0';

  std::cout << ans[(lastDigit % 2) == 0] << '\n';

  for(long i = 0; i < len; i++)
    sum += num[i] - '0';

  std::cout << ans[(sum % 3) == 0] << '\n' << ans[lastDigit == 0 || lastDigit == 5] << '\n';

  return 0;
}
