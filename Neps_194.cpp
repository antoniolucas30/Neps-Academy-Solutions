#include <iostream>
#include <vector>

int main(){

  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  std::vector <int> parValores, imparValores;
  int num, len;

  for(int i = 0; i < 10; i++){

    std::cin >> num;

    if((num % 2) == 0)
      parValores.push_back(num);

    else
      imparValores.push_back(num);

  }

  num = parValores.size(), len = imparValores.size();

  for(int i = 0; i < num; i++){

    if(i != 0)
      std::cout << ' ';

    std::cout << parValores[i];

  }

  std::cout << '\n';

  for(int i = 0; i < len; i++){

    if(i != 0)
      std::cout << ' ';

    std::cout << imparValores[i];

  }

  std::cout << '\n';

  return 0;
}
