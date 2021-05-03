#include <iostream>

int main(){

  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int vec[] = {100, 50, 25, 10, 5, 1}, index = 0;
  long num, result = 0;

  std::cin >> num;

  while(num != 0){

    result += (num) / (vec[index]);
    num -= ((num) / (vec[index])) * vec[index];

    index++;

  }

  std::cout << result << std::endl;

  return 0;
}
