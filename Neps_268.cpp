#include <iostream>

unsigned long long MDC(unsigned long long n1, unsigned long long n2);

int main(){

  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  unsigned long long vec[4], numerador, denominador, MDCNum;

  for(int i = 0; i < 4; i++)
    std::cin >> vec[i];

  denominador = vec[1] * vec[3], numerador = ((denominador / vec[1]) * vec[0]) + ((denominador / vec[3]) * vec[2]);

  MDCNum = MDC(denominador, numerador);

  std::cout << numerador / MDCNum << ' ' << denominador / MDCNum << '\n';

  return 0;
}

unsigned long long MDC(unsigned long long n1, unsigned long long n2){

  if(n1 > n2)
    return MDC(n2, n1);

  else if(n1 < n2)
    return MDC(n1, n2 - n1);

  else
    return n1;

}
