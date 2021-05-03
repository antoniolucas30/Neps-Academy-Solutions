#include <iostream>

using namespace std;

bool flagA;
bool flagB;

int main(){

  flagA = true;
  flagB = true;

  for(int a = 0, b = 1; a <= 31;){

    cout << "a = " << a << " <-> b = " << b << '\n';

    if(flagB)
      b -= 2;

    else
      b += 4;

    flagB = !flagB;

    if(a == 0 || a == 31)
      a++;

    else{

      if(!flagA)
        a++;
      
      flagA = !flagA;

    }


  }

  return 0;
}

