#include <iostream>
#include <algorithm>

int main(){

  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int vecDimensions[3], n1, n2, p1, p2;
  std::string ans = "NS";

  for(int i = 0; i < 3; i++)
    std::cin >> vecDimensions[i];

  std::sort(vecDimensions, vecDimensions + 3);

  std::cin >> n1 >> n2;

  p1 = std::min(n1, n2), p2 = std::max(n1, n2);

  std::cout << ans[p1 >= vecDimensions[0] && p2 >= vecDimensions[1]] << '\n';

  return 0;
}
