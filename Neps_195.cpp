#include <iostream>
#include <iomanip>

void Binary(long long num);

int main(){

  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  long long num;

  std::cin >> num;

  Binary(num);

  std::cout << '\n';

  return 0;
}

void Binary(long long num){

  int ans = (num % 2);

  if(num > 1)
    Binary(num / 2);

  std::cout << ans;

}
  
