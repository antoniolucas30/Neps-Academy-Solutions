#include <iostream>

int main(){

  for(int a = 12; a <= 32; a++){

    std::cout << "a = " << a << " <-> b = " << a + 6 << '\n';
    std::cout << "a = " << a + 2 << " <-> b = " << a + 4 << '\n';
    std::cout << "a = " << a + 6 << " <-> b = " << a << '\n'; 


  }

  return 0;
}
