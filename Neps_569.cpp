#include <iostream>
#include <vector>
#include <queue>
#include <utility>

#define DIST_MAX 10000

int Dijkstra(std::vector <std::vector <int>>& Linhas, std::vector <std::vector <int>>& GraphTerminais, int totalLinhas, int totalTerminais, int source, int dest, int sourceLinha);

int main(){

  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int terminais, linhas, origem, destino, num, result = -1, lenOrigem, currentDijkstra, totalTerminais;
  std::vector <std::vector <int>> Linhas, GraphTerminais;

  std::cin >> terminais >> linhas >> origem >> destino;

  Linhas.resize(linhas); GraphTerminais.resize(terminais);

  for(int i = 0; i < linhas; i++){

    std::cin >> totalTerminais;

    for(int j = 0; j < totalTerminais; j++){

      std::cin >> num; num--;

      Linhas[i].push_back(num);
      GraphTerminais[num].push_back(i);

    }
  }

  origem--, destino--;

  lenOrigem = GraphTerminais[origem].size();

  for(int i = 0; i < lenOrigem; i++){

    currentDijkstra = Dijkstra(Linhas, GraphTerminais, linhas, terminais, origem, destino, GraphTerminais[origem][i]);

    if(result == -1 || currentDijkstra < result)
      result = currentDijkstra;

  }
  
  std::cout << result + 1 << std::endl;
  
  return 0;
}

int Dijkstra(std::vector <std::vector <int>>& Linhas, std::vector <std::vector <int>>& GraphTerminais, int totalLinhas, int totalTerminais, int source, int dest, int sourceLinha){

  std::priority_queue <std::pair <int, int>, std::vector <std::pair <int, int>>, std::greater <std::pair <int, int>>> FilaDijkstra;
  int* vecDists = new int[totalTerminais], currentNode, lenCurrentNode, currentLinha, lenCurrentLinha, currentDist;

  for(int i = 0; i < totalTerminais; i++)
    vecDists[i] = DIST_MAX;

  vecDists[source] = 0;
  FilaDijkstra.push(std::make_pair(0, source));

  while(!FilaDijkstra.empty()){

    currentNode = FilaDijkstra.top().second;
    FilaDijkstra.pop();

    lenCurrentNode = GraphTerminais[currentNode].size();

    for(int i = 0; i < lenCurrentNode; i++){


      currentLinha = GraphTerminais[currentNode][i];
      lenCurrentLinha = Linhas[currentLinha].size();
      
      for(int j = 0; j < lenCurrentLinha; j++){

        if(currentLinha == sourceLinha)
          currentDist = 0;

        else
          currentDist = vecDists[currentNode] + 1;

        if(currentDist < vecDists[Linhas[currentLinha][j]]){

          vecDists[Linhas[currentLinha][j]] = currentDist;
          FilaDijkstra.push(std::make_pair(currentDist, Linhas[currentLinha][j]));

        }

      }

    }

  }

  return vecDists[dest];

}
