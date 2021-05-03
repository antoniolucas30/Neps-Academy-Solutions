#include <iostream>

int main(){

  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  long total, soma, *vec, indexI, indexJ;

  std::cin >> total;

  vec = new long[total];

  for(long i = 0; i < total; i++)
    std::cin >> vec[i];

  std::cin >> soma;

  indexI = 0, indexJ = total - 1;

  while((vec[indexI] + vec[indexJ]) != soma){

    if((vec[indexI] + vec[indexJ]) < soma)
      indexI++;
    
    else
      indexJ--;

  }

  std::cout << vec[indexI] << ' ' << vec[indexJ] << std::endl;

  return 0;
}
