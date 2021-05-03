#include <iostream>

int main(){

  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  bool lA = 0, lB = 0;
  int num;
  long qnt;

  std::cin >> qnt;

  for(long int i = 0; i < qnt; i++){

    std::cin >> num;

    if(num == 1)
      lA = !lA;
    else
      lA = !lA, lB = !lB;

  }

  std::cout << lA << '\n' << lB << std::endl;

  return 0;
}
