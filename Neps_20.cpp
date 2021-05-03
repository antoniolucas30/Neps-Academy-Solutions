#include <iostream>
#include <algorithm>

int main(){

  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int* vec = new int[3];

  for(int i = 0; i < 3; i++)
    std::cin >> vec[i];

  std::sort(vec, vec + 3);

  if(vec[0] == vec[1])
    std::cout << vec[2] << '\n';

  else
    std::cout << vec[0] << '\n';

  return 0;
}
