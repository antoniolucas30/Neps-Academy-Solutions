#include <iostream>

int result = 0;

void Func();

int main(){

  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  Func();

  return 0;
}

void Func(){

  int num;

  result++;

  std::cin >> num;

  if(result < 10)
    Func();

  std::cout << num << '\n';

}
