#include <iostream>
#include <iomanip>

int main(){

  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  long number, minNum, maxNum;
  double total = 0.0;

  std::cin >> number >> minNum >> maxNum;

  for(long i = minNum; i <= maxNum; i++){

    if(i != 0)
      total += number / (double(i));

  }

  std::cout << std::fixed << std::setprecision(5)  << total / (maxNum - minNum + 2) << '\n';

  return 0;
}
