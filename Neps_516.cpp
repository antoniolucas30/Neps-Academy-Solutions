#include <iostream>
#include <algorithm>

int main(){

  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int vec[3];

  for(int i = 0; i < 3; i++)
    std::cin >> vec[i];

  std::sort(vec, vec + 3);

  std::cout << vec[1] << '\n';

  return 0;
}
