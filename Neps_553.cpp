#include <iostream>

int main(){

  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int vec[3];
  std::string ans = "NS";

  for(int i = 0; i < 3; i++)
    std::cin >> vec[i];

  std::cout << ans[((vec[0] * vec[2]) <= vec[1])] << '\n';

  return 0;
}
