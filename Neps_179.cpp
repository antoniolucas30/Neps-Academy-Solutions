#include <iostream>

using namespace std;

int main(){

  for(int a = 0, b = 1; a <= 30; a += 2, b += 3)
    cout << "a = " << a << " <-> b = " << b << "\na = " << a << " <-> b = " << b + 1 << '\n';

  return 0;
}
