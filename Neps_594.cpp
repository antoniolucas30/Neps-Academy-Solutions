#include <iostream>

int MDC(int n1, int n2);
int main(){

  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int maxNum, n1, n2, mdcNum;

  std::cin >> maxNum >> n1 >> n2;

  mdcNum = MDC(n1, n2);

  if((n1 / mdcNum) > maxNum || (n2 / mdcNum) > maxNum)
    std::cout << "IMPOSSIVEL\n";

  else
    std::cout << n1 / mdcNum << ' ' << n2 / mdcNum << '\n';

  return 0;
}

int MDC(int n1, int n2){

  if(n1 == n2)
    return n1;

  else if(n2 > n1)
    return MDC(n2, n1);

  else
    return MDC(n1 - n2, n2);

}
