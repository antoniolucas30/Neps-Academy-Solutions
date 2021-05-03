#include <iostream>

int main(){

  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  long lenVec, *vec;
  bool ans, swapped;
  std::string result[] = {"Carlos", "Marcelo"};

  while(std::cin >> lenVec && lenVec != 0){

    ans = 0, swapped = 1;

    vec = new long[lenVec];

    for(long i = 0; i < lenVec; i++)
      std::cin >> vec[i];

    while(swapped){

      swapped = false;

      for(long i = 0; i < lenVec - 1; i++){

        if(vec[i] > vec[i + 1]){

          swapped = true;
          ans = !ans;

          std::swap(vec[i], vec[i + 1]);

        }

      }

    }

    std::cout << result[ans] << '\n';

    delete[] vec;

  }

  return 0;
}
