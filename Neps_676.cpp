#include <iostream>

int main(){

  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  long lenVec;
  long long *vec, p1, p2;

  std::cin >> lenVec;

  vec = new long long[lenVec];
  
  for(int i = 0; i < lenVec; i++)
    std::cin >> vec[i];

  p1 = vec[lenVec - 1] * vec[lenVec - 2] * vec[lenVec - 3], p2 = vec[0] * vec[1] * vec[lenVec - 1];

  std::cout << std::max(p1, p2) << '\n';

  return 0;
}
