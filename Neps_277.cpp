#include <iostream>
#include <map>
#include <utility>

int main(){

  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  long n1, n2;
  int lenVec, lenInternet;
  std::map <long, std::pair <long, bool>> MapChange;

  std::cin >> lenVec >> lenInternet;

  for(int i = 0; i < lenVec; i++){
    
    std::cin >> n1 >> n2;
    MapChange[n1] = std::make_pair(n2, false);
  
  }

  for(int i = 0; i < lenInternet; i++){

    std::cin >> n1 >> n2;
    
    if(n2 > MapChange[n1].first)
      MapChange[n1].first = n2, MapChange[n1].second = true;

  }

  for(std::map <long, std::pair <long, bool>>::iterator it = MapChange.begin(); it != MapChange.end(); it++){

    if((*it).second.second == true){

      std::cout << (*it).first << ' ' << (*it).second.first << '\n';

    } 

  }


  return 0;
}
