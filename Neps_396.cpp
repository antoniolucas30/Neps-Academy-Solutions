#include <iostream>

int main(){

  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int vec1[10];
  int vec2[10];
  int whichNum;
  int totalSize = 0;

  for(int i = 0; i < 10; i++)
    std::cin >> vec1[i];

  std::cin >> whichNum;

  for(int i = 0; i < 10; i++){

    if(vec1[i] == whichNum)
      vec2[totalSize++] = i;

  }

  if(totalSize == 0)
    std::cout << "Mia x";

  else{

    std::cout << totalSize << '\n';

    for(int i = 0; i < totalSize; i++){

      if(i != 0)
        std::cout << ' ';

      std::cout << vec2[i];

    }

  }

  std::cout << '\n';

  return 0;
}
