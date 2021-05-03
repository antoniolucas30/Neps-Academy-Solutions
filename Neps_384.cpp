#include <iostream>
#include <vector>
#include <algorithm>

int main(){
  
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  long lenVec, identifier;
  std::vector <int> vec;

  std::cin >> lenVec;

  for(long i = 0; i < lenVec; i++){

    std::cin >> identifier;
    vec.push_back(identifier);

  }

  std::cin >> lenVec;

  for(long i = 0; i < lenVec; i++){

    std::cin >> identifier;
    vec.erase(std::find(vec.begin(), vec.end(), identifier));

  }

  lenVec = vec.size();

  for(long i = 0; i < lenVec; i++){

    if(i != 0)
      std::cout << ' ';

    std::cout << vec[i];

  }

  std::cout << std::endl;

  return 0;
}
