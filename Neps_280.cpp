#include <iostream>
#include <cmath>

int main(){

  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  long long num;
  bool result = true;

  std::cin >> num;

  for(long long i = 2; i <= double(std::sqrt(num)); i++){

    if((num % i) == 0){
    
      result = false;
      break;

    }

  }

  if(!result || num == 1)
    std::cout << "N\n";

  else if(result || num == 2)
    std::cout << "S\n";


  return 0;
}
