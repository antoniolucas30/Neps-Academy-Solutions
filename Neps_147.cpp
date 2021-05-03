#include <iostream>

int main(){

  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n1, n2, media;

  std::cin >> n1 >> n2;

  media = ((n1 * 2) + (n2 * 3))/5;

  if(media >= 7)
    std::cout << "Aprovado\n";

  else if(media < 3)
    std::cout << "Reprovado\n";

  else
    std::cout << "Final\n";

  return 0;
}
