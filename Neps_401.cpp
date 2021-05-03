#include <iostream>
#include <vector>

int main(){

  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int vec[10], minNum = 1000, lenVec;
  std::vector <int> allIndexes;

  for(int i = 0; i < 10; i++){

    std::cin >> vec[i];

    if(vec[i] < minNum){

      allIndexes.clear();
      allIndexes.push_back(i);

      minNum = vec[i];

    }

    else if(vec[i] == minNum)
      allIndexes.push_back(i);

  }

  std::cout << "Menor: " << minNum << '\n';

  lenVec = allIndexes.size();

  std::cout << "Ocorrencias:";

  for(int i = 0; i < lenVec; i++)
    std::cout << ' ' << allIndexes[i];

  std::cout << '\n';

  for(int i = 0; i < 10; i++){

    if(i != 0)
      std::cout << ' ';

    if(vec[i] == minNum)
      std::cout << "-1";

    else
      std::cout << vec[i];

  }

  std::cout << '\n';

  return 0;
}
