#include <iostream>

int main(){

  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int lenVec, lenOp, *vec, max, nodeU, nodeV, current = 0;
  bool print;

  while(std::cin >> lenVec >> lenOp && lenVec != 0 && lenOp != 0){

    vec = new int[lenVec]{0}, max = 0;
    print = false;

    for(int i = 0; i < lenOp; i++){

      std::cin >> nodeU >> nodeV;

      vec[nodeU - 1]++, vec[nodeV - 1]++;

      if(vec[nodeU - 1] > max)
        max = vec[nodeU - 1];

      else if(vec[nodeV - 1] > max)
        max = vec[nodeV - 1];

    }

    std::cout << "Teste " << ++current << '\n';

    for(int i = 0; i < lenVec; i++){
  
      if(vec[i] == max){

        if(print)
          std::cout << ' ';

        print = true;

        std::cout << i + 1;

      }

    }

    std::cout << "\n\n";

    delete[] vec;

  }

  return 0;
}
