#include <iostream>

int main(){

  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int A, B, C, D;
  std::string ans = "NS";

  std::cin >> A >> B >> C >> D;

  std::cout << ans[(A == (B + C + D) && D == (C + B) && C == B)] << '\n';

  return 0;
}
