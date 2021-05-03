#include <iostream>
#include <vector>
#include <algorithm>

int main(){

  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int totalMeters, lenIntervalos, start, end, lenVec;
  std::vector <std::pair <int, int>> VecMeters;

  std::cin >> totalMeters >> lenIntervalos;

  for(int i = 0; i < lenIntervalos; i++){

    std::cin >> start >> end;

    lenVec = VecMeters.size();

    VecMeters.push_back(std::make_pair(start, end));

  }

  std::sort(VecMeters.begin(), VecMeters.end());
  lenVec = VecMeters.size();

  for(int i = 0; i < lenVec - 1; i+=0){

    if(VecMeters[i].first <= VecMeters[i + 1].first && VecMeters[i].second >= VecMeters[i + 1].first){

      if(VecMeters[i].second < VecMeters[i + 1].second)
        VecMeters[i].second = VecMeters[i + 1].second;

      VecMeters.erase(VecMeters.begin() + i + 1);
      lenVec--;

    }

    else
      i++;

  }

  lenVec = VecMeters.size();

  for(int i = 0; i < lenVec; i++)
    std::cout << VecMeters[i].first << ' ' << VecMeters[i].second << '\n';

  std::cout << std::endl;

  return 0;
}
