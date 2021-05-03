#include <iostream>
#include <vector>

bool result = 1;

int BFS(std::vector <std::vector <long>>& Graph, int initial);

int main(){

  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  std::string ans[] = {"mal", "bem"};
  long lenVec, nodeU, nodeV;
  std::vector <std::vector <long>> Graph;

  std::cin >> lenVec;

  Graph.resize(lenVec + 1);

  for(long i = 0; i < lenVec; i++){

    std::cin >> nodeU >> nodeV;

    Graph[nodeV].push_back(nodeU);

  }

  BFS(Graph, 0);

  std::cout << ans[result] << '\n';

  return 0;
}

int BFS(std::vector <std::vector <long>>& Graph, int initial){

  int lenCurrentNode = Graph[initial].size(), n1 = 1, n2 = 1, total = 1;

  for(int i = 0; i < lenCurrentNode; i++){

    if(result == false)
      break;

    if(i == 0){
      
      n1 += BFS(Graph, Graph[initial][i]);
      total += n1;

    }

    else{

      n2 += BFS(Graph, Graph[initial][i]);

      if(n1 != n2){

        result = false;
        break;

      }

      total += n2;

      n2 = 1;

    }

  }

  return total;

}
