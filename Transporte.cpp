#include <iostream>

using namespace std;

long maximaMetro;
long minimaMetro;
double novaMaxima;

int main(){

  cin >> maximaMetro >> minimaMetro;

  novaMaxima = maximaMetro * 0.3;

  if(novaMaxima >= minimaMetro)
    cout << long(novaMaxima) << '\n';
  
  else
    cout << 0 << '\n';

  return 0;
}