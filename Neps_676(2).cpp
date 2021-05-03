#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int>pii;
typedef pair<int, pair<int,int> > pipii;

#define INF 99999999
#define MAXN 120


int dist[MAXN][MAXN];
int processado[MAXN][MAXN];


int n;
int v[MAXN][MAXN];

bool can(int i,int j){
  return (i>=0 && i<n) && (j>=0 && j<n);
}

void dijkstra(int x,int y){
  vector<pii>m={{1,0},{0,1},{0,-1},{-1,0}};
  // memset(dist,INF,sizeof(dist));
  for(int i=0;i<n;i++){
    for(int j=0;j<n;++j){
      dist[i][j]=INF;
    }
  }
  dist[x][y]=0;

  priority_queue<pipii,vector<pipii>,greater<pipii> > fila;
  // fila.push(make_pair(0,make_pair(i,j)));
  fila.push(pipii(0,pii(x,y)));

  int davez=-1;
  int menor=INF;

  while(!fila.empty()){
    x=fila.top().second.first;
    y=fila.top().second.second;
    // int atual=fila.top().second;
    fila.pop();

    for(auto k:m){
      int i=x+k.first;
      int j=y+k.second;
      if(can(i,j)){
        int distancia=v[i][j];
        if(dist[i][j]>dist[x][y]+distancia){
          dist[i][j]=dist[x][y]+distancia;
          fila.push(pipii(dist[i][j],pii(i,j)));
        }
      }
    }

  }


}

int main(){
  cin>>n;
  memset(processado,false,sizeof(processado));
  for(int i=0;i<n;i++){
    for(int j=0;j<n;++j){
      cin>>v[i][j];
    }
  }

  dijkstra(0,0);
  cout<<dist[n-1][n-1]<<endl;

}
