#include <iostream>
#include <vector>
#include <queue>
#include <utility>

#define INT_MAX 100001

long Dijkstra(std::vector <std::vector <long>>& Graph, std::vector <std::vector <long>>& GraphPortals, long totalCities);

int main(){

  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  long cities, capacity, quantity, *vecPortals, result;
  std::vector <std::vector <long>> Graph, GraphPortals;

  std::cin >> cities >> capacity >> quantity;

  vecPortals = new long[capacity];
  Graph.resize(cities);
  GraphPortals.resize(quantity);

  for(long int i = 0; i < quantity; i++){

    for(long int j = 0; j < capacity; j++){
      
      std::cin >> vecPortals[j];

      Graph[vecPortals[j] - 1].push_back(i);
      GraphPortals[i].push_back(vecPortals[j] - 1);

    }

  }

  result = Dijkstra(Graph, GraphPortals, cities);

  if(result == INT_MAX)
    std::cout << -1 << '\n';
  else
    std::cout << result + 1 << '\n';

  return 0;
}

long Dijkstra(std::vector <std::vector <long>>& Graph, std::vector <std::vector <long>>& GraphPortals, long totalCities){

  long* dists = new long[totalCities], currentDist, currentCity, lenCurrent, cityFor, currentIndex;
  std::priority_queue <std::pair <int, int>, std::vector <std::pair <int,int>>, std::greater <std::pair <int, int>>> cities;

  for(int i = 0; i < totalCities; i++)
    dists[i] = INT_MAX;

  dists[0] = 0;
  cities.push(std::make_pair(0, 0));

  while(!cities.empty()){

    currentDist = cities.top().first, currentCity = cities.top().second;

    cities.pop();

    lenCurrent = Graph[currentCity].size();

    for(long i = 0; i < lenCurrent; i++){

      currentDist = dists[currentCity] + 1;
      currentIndex = GraphPortals[Graph[currentCity][i]].size();

      for(long j = 0; j < currentIndex; j++){

        cityFor = GraphPortals[Graph[currentCity][i]][j];

        if(currentDist < dists[cityFor]){

          dists[cityFor] = currentDist;
          cities.push(std::make_pair(currentDist, cityFor));

        }

      }

    }

  }

  return dists[totalCities - 1];

}

