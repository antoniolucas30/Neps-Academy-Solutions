#include <iostream>
#include <vector>
#include <algorithm>

struct Edge{
  
  int dist, nodeU, nodeV;

};

bool Compare(Edge x1, Edge x2);
int Find(int x, int* vec);
void Join(int* vec, int* dist, int n1, int n2);

int main(){

  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int lenNodes, lenEdges, *Pais, *Dists, nodeU, nodeV, dist;
  long result = 0;
  std::vector <Edge> Graph;

  std::cin >> lenNodes >> lenEdges;

  Pais = new int[lenNodes], Dists = new int[lenNodes];

  for(int i = 0; i < lenNodes; i++)
    Pais[i] = i, Dists[i] = 0;

  for(int i = 0; i < lenEdges; i++){

    std::cin >> nodeU >> nodeV >> dist;
    Graph.push_back({dist, nodeU, nodeV});

  }

  std::sort(Graph.begin(), Graph.end(), Compare);

  for(int i = 0; i < lenEdges; i++){

    if(Find(Graph[i].nodeU, Pais) != Find(Graph[i].nodeV, Pais)){

      Join(Pais, Dists, Graph[i].nodeU, Graph[i].nodeV);
      result += Graph[i].dist;

    }

  }

  std::cout << result << '\n';

  return 0;
}

bool Compare(Edge x1, Edge x2){

  return x1.dist < x2.dist;

}

int Find(int x, int* vec){

  if(vec[x] == x)
    return x;

  return vec[x] = Find(vec[x], vec);

}

void Join(int* vec, int* dist, int n1, int n2){

  int p1 = Find(n1, vec), p2 = Find(n2, vec);

  if(dist[p1] < dist[p2])
    vec[p1] = p2;

  else if(dist[p2] < dist[p1])
    vec[p2] = p1;

  else{

    vec[p1] = p2;
    dist[p2]++;

  }

}
