#include <iostream>

using namespace std;

int qntAndar1;
int qntAndar2;
int qntAndar3;
int minutosAndar1;
int minutosAndar2;
int minutosAndar3;
int result;

int main(){

  cin >> qntAndar1 >> qntAndar2 >> qntAndar3;

  minutosAndar1 = qntAndar2 * 2 + qntAndar3 * 4;
  minutosAndar2 = qntAndar1 * 2 + qntAndar3 * 2;
  minutosAndar3 = qntAndar1 * 4 + qntAndar2 * 2;

  result = min(minutosAndar1, min(minutosAndar2, minutosAndar3));

  cout << result << '\n';

  return 0;
}
