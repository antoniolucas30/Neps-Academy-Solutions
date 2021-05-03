#include <iostream>
#include <algorithm>
#include <vector>

struct Edge{

  int nodeU, nodeV, distance;

};
int Find(int n1, int* vecPai);
void Union(int n1, int n2, int* vecPai, int* vecPaiTotal);
bool Compare(Edge n1, Edge n2);

int main(){

  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int qntNodes, qntEdges, nodeU, nodeV, distance, tamVec, *vecPai, *vecPaiTotal, current = 0;
  Edge* vecEdges;
  std::vector <Edge> vecAnswer;

  while(std::cin >> qntNodes >> qntEdges && qntNodes != 0 && qntEdges != 0){

    vecEdges = new Edge[qntEdges];
    vecPai = new int[qntNodes], vecPaiTotal = new int[qntNodes]{0};

    for(int i = 0; i < qntNodes; i++)
      vecPai[i] = i;

    for(int i = 0; i < qntEdges; i++){

      std::cin >> nodeU >> nodeV >> distance;

      nodeU--, nodeV--;

      vecEdges[i] = {nodeU, nodeV, distance};

    }

    std::sort(vecEdges, vecEdges + qntEdges, Compare);

    for(int i = 0; i < qntEdges; i++){

      if(vecPai[vecEdges[i].nodeU] != vecPai[vecEdges[i].nodeV]){

        vecAnswer.push_back(vecEdges[i]);
        Union(vecEdges[i].nodeU, vecEdges[i].nodeV, vecPai, vecPaiTotal);

      }

    }

    tamVec = vecAnswer.size();

    std::cout << "Teste " << ++current << '\n';

    for(int i = 0; i < tamVec; i++){

      if(vecAnswer[i].nodeU > vecAnswer[i].nodeV)
        std::cout << vecAnswer[i].nodeV + 1 << ' ' << vecAnswer[i].nodeU + 1 << '\n';

      else
        std::cout << vecAnswer[i].nodeU + 1 << ' ' << vecAnswer[i].nodeV + 1 << '\n';

    }

    std::cout << '\n';

    vecAnswer.clear();
    delete[] vecEdges; delete[] vecPai, delete[] vecPaiTotal;

  }

  return 0;
}

int Find(int n1, int* vecPai){

  if(vecPai[n1] == n1)
    return n1;

  return vecPai[n1] = Find(vecPai[n1], vecPai);

}

void Union(int n1, int n2, int* vecPai, int* vecPaiTotal){

  int p1 = Find(n1, vecPai), p2 = Find(n2, vecPai);

  if(vecPaiTotal[p1] > vecPaiTotal[p2])
    vecPai[p2] = p1;

  else if(vecPaiTotal[p2] > vecPaiTotal[p1])
    vecPai[p1] = p2;

  else{

    vecPai[p1] = p2;
    vecPaiTotal[p2]++;

  }

}

bool Compare(Edge n1, Edge n2){

  return n1.distance <= n2.distance;

}
