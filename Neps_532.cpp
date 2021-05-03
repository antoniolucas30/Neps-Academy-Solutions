#include <iostream>
#include <vector>

void DFS(std::vector <std::vector <long>>& edges, long currentCity, long currentDist, long* result, bool* presence);

int main(){

  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  long cities;
  long cityU;
  long cityV;
  long result = 0;
  long* vecQnt;
  bool* presence;
  std::vector <std::vector <long>> edges;

  std::cin >> cities;

  vecQnt = new long[cities]{0};
  presence = new bool[cities]{0};
  edges.resize(cities);

  for(long i = 0; i < cities - 1; i++){

    std::cin >> cityU >> cityV;

    cityU--;
    cityV--;

    vecQnt[cityU]++;
    vecQnt[cityV]++;

    edges[cityU].push_back(cityV);
    edges[cityV].push_back(cityU);

  }

  for(long i = 0; i < cities; i++){

    //if(vecQnt[i] == 1){
      
      std::cout << "FOI NESSE: " << i + 1 << '\n';

      DFS(edges, i, 0, &result, presence);
      //break;

    //}

  }

  std::cout << result << '\n';

  return 0;
}

void DFS(std::vector <std::vector <long>>& edges, long currentCity, long currentDist, long* result, bool* presence){

  long totalVec = edges[currentCity].size();
  
  presence[currentCity] = 1;

  if(currentDist > (*result))
    (*result) = currentDist;

  for(long i = 0; i < totalVec; i++){

    if(!presence[edges[currentCity][i]])
      DFS(edges, edges[currentCity][i], currentDist + 1, result, presence);

  }

}
