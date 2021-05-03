#include <iostream>

int main(){

  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  std::string result = "NS";
  int vec[3];

  for(int i = 0; i < 3; i++)
    std::cin >> vec[i];

  std::cout << result[vec[0] < vec[1] && vec[1] > 50 && vec[1] > vec[2]] << '\n';

  return 0;
}
