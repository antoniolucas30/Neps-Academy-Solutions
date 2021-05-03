#include <iostream>

int main(){
  
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n1, n2, totJogos = 8;
  std::string teams = "ABCDEFGHIJKLMNOP";

  while(totJogos != 0){

    for(int i = 0, lastIndex = 0; i < totJogos; i++){

      std::cin >> n1 >> n2;

      if(n1 > n2)
        teams.erase(lastIndex + 1, 1);

      else
        teams.erase(lastIndex, 1);

      lastIndex++;

    }

    totJogos /= 2;

  }

  std::cout << teams << std::endl;

  return 0;
}

