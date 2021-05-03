#include <iostream>

long GCD(long n1, long n2);

int main(){

  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  long totalNum, lastNum, currentNum;

  std::cin >> totalNum;

  for(int i = 0; i < totalNum; i++){

    std::cin >> currentNum;

    if(i == 0)
      lastNum = currentNum;

    else{

      lastNum = GCD(currentNum, lastNum);

    }
      
  }

  std::cout << lastNum << '\n';

  return 0;
}

long GCD(long n1, long n2){

  if(n1 > n2)
    return GCD(n2, n1);

  else if(n1 < n2)
    return GCD(n1, n2 - n1);

  else
    return n1;

}
