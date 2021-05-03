#include <iostream>
#include <vector>
#include <utility>
#include <queue>

#define DIST_MAX 10000001

long Dijkstra(std::vector <std::vector <std::pair <int, int>>>& Graph, int totalCities);

int main(){

  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int totalCities, totalEdges, nodeU, nodeV, cost;
  std::vector <std::vector <std::pair <int,int>>> Graph;

  std::cin >> totalCities >> totalEdges;

  Graph.resize(totalCities);

  for(int i = 0;i < totalEdges; i++){

    std::cin >> nodeU >> nodeV >> cost;

    nodeU--, nodeV--;

    Graph[nodeU].push_back(std::make_pair(nodeV, cost));
    Graph[nodeV].push_back(std::make_pair(nodeU, cost));

  }

  std::cout << Dijkstra(Graph, totalCities) << std::endl;

  return 0;
}

long Dijkstra(std::vector <std::vector <std::pair <int, int>>>& Graph, int totalCities){

  long* dists = new long[totalCities];
  std::priority_queue <std::pair <int, int>, std::vector <std::pair <int, int>>, std::greater <std::pair <int, int>>> Cities;
  int lenCurrentNode, currentNode, nodeFor, distFor;

  for(int i = 0; i < totalCities; i++)
    dists[i] = DIST_MAX;

  Cities.push(std::make_pair(0, 0));
  dists[0] = 0;

  while(!Cities.empty()){

    currentNode = Cities.top().second;
    lenCurrentNode = Graph[currentNode].size();

    Cities.pop();

    for(int i = 0; i < lenCurrentNode; i++){

      nodeFor = Graph[currentNode][i].first;
      distFor = dists[currentNode] + Graph[currentNode][i].second;

      if(distFor < dists[nodeFor]){

        dists[nodeFor] = distFor;
        Cities.push(std::make_pair(distFor, nodeFor));

      }

    }

  }

  return dists[totalCities - 1];

}
