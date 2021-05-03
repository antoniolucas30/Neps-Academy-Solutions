#include <iostream>

int main(){

  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  long qntCities, iterations, **vecCities, cityU, cityV, index;
  bool op;

  std::cin >> qntCities >> iterations;

  vecCities = new long*[qntCities];

  for(long i = 0; i < qntCities; i++){

    vecCities[i] = new long[100];
    vecCities[i][0] = -1;

  }

  for(long i = 0; i < iterations; i++){

    std::cin >> op >> cityU >> cityV;

    if(op){

      index = 0;

      while(1){

        if(vecCities[cityV][index] == -1){

          vecCities[cityV][index] = cityU;

          if(index < 99)
            vecCities[cityV][index + 1] = -1;

          break;

        }

        index++;

      }

      index = 0;

      while(1){

        if(vecCities[cityU][index] == -1){

          vecCities[cityU][index] = cityV;

          if(index < 99)
            vecCities[cityU][index + 1] = -1;

          
          break;
        
        }

        index++;

      }

    }

    else{

      index = 0;

      while(index <= 99 && vecCities[cityV][index] != -1){

        if(vecCities[cityV][index] == cityU){

          op = 1;
          break;

        }

        index++;

      }

      std::cout << op << '\n';

    }

  }

  return 0;
}
