#include <iostream>
#include <vector>
#include <utility>
#include <cmath>

#define INT_MAX 100000

void Dijkstra(std::vector <std::pair <long, long>>& Positions, int distanceMax, int totalPositions, int* result);

int main(){

  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  std::string ans = "NS";
  int total, distance, result;
  long posX, posY;
  std::vector <std::pair <long, long>> Positions;

  std::cin >> total >> distance;

  Positions.resize(total);

  for(int i = 0; i < total; i++){

    std::cin >> posX >> posY;
    Positions[i] = std::make_pair(posX, posY);

  }

  result = total - 1;

  Dijkstra(Positions, distance, total, &result);

  std::cout << ans[result == 0] << std::endl;

  return 0;
}

void Dijkstra(std::vector <std::pair <long, long>>& Positions, int distanceMax, int totalPositions, int* result){

  std::vector <int> allPositions;
  int *dists, currentDistance, currentPosition, lenVec, currentIndex;

  dists = new int[totalPositions];

  for(int i = 0; i < totalPositions; i++){

    allPositions.push_back(i); 
    dists[i] = INT_MAX;  

  }

  dists[0] = 0;

  while(!allPositions.empty()){

    currentDistance = INT_MAX, currentPosition = allPositions[0], lenVec = allPositions.size(), currentIndex = 0;

    for(int i = 0; i < lenVec; i++){

      if(dists[allPositions[i]] < currentDistance){

        currentDistance = dists[allPositions[i]];
        currentPosition = allPositions[i];
        currentIndex = i;

      }

    }

    allPositions.erase(allPositions.begin() + currentIndex);

    for(int i = 0; i < totalPositions; i++){

      if(i != currentPosition){

        currentDistance = dists[currentPosition] + 1;

        if(currentDistance < dists[i] && double(std::sqrt(std::pow(Positions[i].second - Positions[currentPosition].second, 2) + std::pow(Positions[i].first - Positions[currentPosition].first, 2))) <= distanceMax){

          if(dists[i] == INT_MAX)
            (*result)--;

          dists[i] = currentDistance;

        }

      }

    }

  }


}
