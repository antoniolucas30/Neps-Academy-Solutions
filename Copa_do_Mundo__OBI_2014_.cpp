#include <iostream>
#include <vector>
#include <algorithm>

struct Edge{

  int dist, nodeU, nodeV;

};

bool Compare(Edge n1, Edge n2);
int Find(int x, int* vec);
void Join(int* vec, int* dist, int n1, int n2);

int main(){

  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int lenCities, lenFerrovias, lenRodovias, cost, *Pais, *Dist, nodeU, nodeV;
  std::vector <Edge> Ferrovias, Rodovias;
  long result = 0;

  std::cin >> lenCities >> lenFerrovias >> lenRodovias;

  Pais = new int[lenCities], Dist = new int[lenCities];

  for(int i = 0; i < lenCities; i++)
    Pais[i] = i, Dist[i] = 0;

  for(int i = 0; i < lenFerrovias; i++){

    std::cin >> nodeU >> nodeV >> cost;

    nodeU--, nodeV--;

    Ferrovias.push_back({cost, nodeU, nodeV});

  }

  std::sort(Ferrovias.begin(), Ferrovias.end(), Compare);

  for(int i = 0; i < lenFerrovias; i++){

    if(Find(Ferrovias[i].nodeU, Pais) != Find(Ferrovias[i].nodeV, Pais)){

      Join(Pais, Dist, Ferrovias[i].nodeU, Ferrovias[i].nodeV);
      result += Ferrovias[i].dist;

    }

  }

  for(int i = 0; i < lenRodovias; i++){

    std::cin >> nodeU >> nodeV >> cost;

    nodeU--, nodeV--;

    Rodovias.push_back({cost, nodeU, nodeV});

  }

  std::sort(Rodovias.begin(), Rodovias.end(), Compare);

  for(int i = 0; i < lenRodovias; i++){

    if(Find(Rodovias[i].nodeU, Pais) != Find(Rodovias[i].nodeV, Pais)){

      Join(Pais, Dist, Rodovias[i].nodeU, Rodovias[i].nodeV);
      result += Rodovias[i].dist;

    }

  }

  std::cout << result << '\n';

  return 0;
}

bool Compare(Edge n1, Edge n2){

  return n1.dist < n2.dist;

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
