#include <iostream>
#include <vector>
#include <algorithm>

struct Aresta{

  int dist, nodeU, nodeV;

};

bool Compare(Aresta x1, Aresta x2);
int Find(int x, int* vec);
void Join(int* vec, int n1, int n2, int* dist);

int main(){

  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  std::vector <Aresta> Graph;
  int lenCities, currentDist, nodeU, nodeV, *vec, *dist;
  long lenEdges, result = 0;

  std::cin >> lenCities >> lenEdges;

  vec = new int[lenCities], dist = new int[lenCities];

  for(int i = 0; i < lenCities; i++)
    vec[i] = i, dist[i] = 0;

  for(long i = 0; i < lenEdges; i++){

    std::cin >> nodeU >> nodeV >> currentDist;
    nodeU--, nodeV--;

    Graph.push_back({currentDist, nodeU, nodeV});

  }

  std::sort(Graph.begin(), Graph.end(), Compare);

  for(long i = 0; i < lenEdges; i++){

    if(Find(Graph[i].nodeU, vec) != Find(Graph[i].nodeV, vec)){

      Join(vec, Graph[i].nodeU, Graph[i].nodeV, dist);
      result += Graph[i].dist;

    }

  }

  std::cout << result << '\n';

  return 0;
}

bool Compare(Aresta x1, Aresta x2){

  return x1.dist < x2.dist;

}

int Find(int x, int* vec){

  if(vec[x] == x)
    return x;

  return vec[x] = Find(vec[x], vec);

}

void Join(int* vec, int n1, int n2, int* dist){

  int p1 = Find(n1, vec), p2 = Find(n2, vec);

  if(dist[p1] < dist[p2])
    vec[p1] = p2;

  else if(dist[p1] > dist[p2])
    vec[p2] = p1;

  else{

    vec[p1] = p2;
    dist[p2]++;

  }

}
