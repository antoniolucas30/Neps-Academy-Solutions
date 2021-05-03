#include <iostream>

int main(){

  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int num, biggest;
  bool flag = false;

  while(std::cin >> num && num != 0){

    if(!flag)
      biggest = num;

    else if(num > biggest)
      biggest = num;

    flag = true;

  }

  std::cout << biggest << '\n';

  return 0;
}
