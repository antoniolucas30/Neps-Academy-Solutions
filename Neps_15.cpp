#include <iostream>
#include <cmath>
#include <iomanip>

int main(){

  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int cabin, totalStudents;

  std::cin >> cabin >> totalStudents;

  std::cout << std::fixed << std::setprecision(0) << std::ceil(double(totalStudents) / (cabin - 1)) << '\n';

  return 0;
}
