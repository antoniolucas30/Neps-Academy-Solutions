#include <iostream>

int main(){

  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int vec[4];
  std::string ans = "FV";

  for(int i = 0; i < 4; i++)
    std::cin >> vec[i];

  std::cout << ans[((vec[0] == vec[2] && vec[1] != vec[3]) || (vec[1] == vec[3] && vec[0] != vec[2]))] << '\n';

  return 0;
}
