#include <iostream>
#include <vector>

void DFS(std::vector <std::vector <int>>& Graph, int source, bool* hasFamily);

int main(){

  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  bool* hasFamily;
  std::vector <std::vector <int>> Graph;
  long totalRelations, totalPeople, personU, personV, result = 0;

  std::cin >> totalPeople >> totalRelations;

  hasFamily = new bool[totalPeople]{0};
  Graph.resize(totalPeople);

  for(long i = 0; i < totalRelations; i++){

    std::cin >> personU >> personV;

    personU--, personV--;

    Graph[personU].push_back(personV);
    Graph[personV].push_back(personU);

  }

  for(long i = 0; i < totalPeople; i++){

    if(hasFamily[i] == 0){

      result++;
      DFS(Graph, i, hasFamily);

    }

  }

  std::cout << result << std::endl;

  return 0;
}

void DFS(std::vector <std::vector <int>>& Graph, int source, bool* hasFamily){

  int lenCurrentNode = Graph[source].size(), nodeFor;

  hasFamily[source] = 1;

  for(long i = 0; i < lenCurrentNode; i++){

    nodeFor = Graph[source][i];

    if(hasFamily[nodeFor] == 0)
      DFS(Graph, nodeFor, hasFamily);

  }

}
