#include <iostream>

int main(){

  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int totalRounds, dario = 0, xerxes = 0, nD, nX;
  std::string result[] = {"dario", "xerxes"};

  std::cin >> totalRounds;

  for(int i = 0; i < totalRounds; i++){

    std::cin >> nD >> nX;

    if(nX == ((nD + 1) % 5) || nX == ((nD + 2) % 5))
      dario++;
    
    else
      xerxes++;

  }

  std::cout << result[xerxes > dario] << '\n';

  return 0;
}
