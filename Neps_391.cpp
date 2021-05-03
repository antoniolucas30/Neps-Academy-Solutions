#include <iostream>

int main(){

  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int total, height, current, last, result = 0, diff;

  std::cin >> total >> height;

  for(int i = 0; i < total; i++){

    std::cin >> current;

    if(i != 0){

      if(last != height){

        diff = height - last;
        last = height;
        current += diff;

        (diff < 0) ? diff *= -1 : diff += 0;

        result += diff;

      }

    }

    last = current;

  }

  std::cout << result << std::endl;

  return 0;
}
