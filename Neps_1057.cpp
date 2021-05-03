#include <iostream>
#include <algorithm>

int main(){

  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  long lenResto, pos, *resto, currentResto, x, y;

  std::cin >> lenResto >> pos;

  resto = new long[lenResto];

  for(long i = 0; i < lenResto; i++){

    std::cin >> x >> y;

    currentResto = x - ((x / y) * y);

    if(currentResto < 0)
      currentResto = 0;

    resto[i] = currentResto;

  }

  std::sort(resto, resto + lenResto);

  std::cout << resto[pos - 1] << '\n';

  return 0;
}
