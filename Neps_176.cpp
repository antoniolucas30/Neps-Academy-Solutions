#include <iostream>
#include <algorithm>

int main(){

  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  long total, *vec;

  std::cin >> total;

  vec = new long[total];

  for(long i = 0; i < total; i++)
    std::cin >> vec[i];

  std::sort(vec, vec + total);

  for(long i = 0; i < total; i++){

    if(i != 0)
      std::cout << ' ';
    std::cout << vec[i];

  }

  std::cout << std::endl;

  return 0;
}
