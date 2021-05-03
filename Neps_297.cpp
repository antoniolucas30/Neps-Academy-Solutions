#include <iostream>
#include <vector>
#include <queue>
#include <utility>

#define INF_NUM 10000000

long Dijkstra(std::vector <std::vector <std::pair <int, int>>>& Graph, int numNodes);

int main(){

  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int numNodes, numBridges, nodeU, nodeV, dist;
  std::vector <std::vector <std::pair <int, int>>> Graph;

  std::cin >> numNodes >> numBridges;

  Graph.resize(numNodes + 2);

  for(int i = 0; i < numBridges; i++){

    std::cin >> nodeU >> nodeV >> dist;

    Graph[nodeU].push_back(std::make_pair(nodeV, dist));
    Graph[nodeV].push_back(std::make_pair(nodeU, dist));

  }

  std::cout << Dijkstra(Graph, numNodes) << '\n';

  return 0;

}

long Dijkstra(std::vector <std::vector <std::pair <int, int>>>& Graph, int numNodes){

  long* dists = new long[numNodes + 2], lenNode, currentNode, currentDist, nodeFor; 
  std::priority_queue <std::pair <int, int>, std::vector <std::pair <int, int>>, std::greater <std::pair <int, int>>> Queue;

  for(int i = 0; i < numNodes + 2; i++)
    dists[i] = INF_NUM;

  dists[0] = 0;

  Queue.push({0, 0});

  while(!Queue.empty()){

    currentNode = Queue.top().second;
    lenNode = Graph[currentNode].size();

    Queue.pop();

    for(int i = 0; i < lenNode; i++){

      nodeFor = Graph[currentNode][i].first, currentDist = Graph[currentNode][i].second;

      if(dists[currentNode] + currentDist < dists[nodeFor]){

        dists[nodeFor] = dists[currentNode] + currentDist;
        Queue.push({dists[nodeFor], nodeFor});

      }

    }

  }

  return dists[numNodes + 1];

}
