#include <iostream>

int main(){

  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int vec[4], currentMin, reunionMin;

  for(int i = 0; i < 4; i++)
    std::cin >> vec[i];

  currentMin = (vec[0] * 60) + vec[1] + 45, reunionMin = (vec[2] * 60) + vec[3];

  if(currentMin <= reunionMin)
    std::cout << "Sucesso\n";

  else
    std::cout << "Atrasado " << currentMin - reunionMin << '\n';

  return 0;
}
