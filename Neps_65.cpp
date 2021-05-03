#include <iostream>
#include <vector>
#include <utility>
#include <queue>

#define DIST_MAX 200

int Dijkstra(bool** matrix, int total);

int movI[] = {0, 0, -1, 1};
int movJ[] = {1, -1, 0, 0};

int main(){

  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int num;
  bool **maze;

  std::cin >> num;

  maze = new bool*[num];

  for(int i = 0; i < num; i++){

    maze[i] = new bool[num];

    for(int j = 0; j < num; j++)
      std::cin >> maze[i][j];

  }

  std::cout << Dijkstra(maze, num) << std::endl;

  return 0;
}

int Dijkstra(bool** matrix, int total){

  std::priority_queue <std::vector <int>, std::vector <std::vector <int>>, std::greater <std::vector <int>>> Points;
  int **dists = new int*[total], currentDist, posI, posJ, posIFor, posJFor;

  for(int i = 0; i < total; i++){

    dists[i] = new int[total];

    for(int j = 0; j < total; j++)
      dists[i][j] = DIST_MAX;

  }

  dists[0][0] = 0;
  Points.push({0, 0, 0});

  while(!Points.empty()){

    posI = Points.top()[1], posJ = Points.top()[2];
    Points.pop();

    for(int i = 0; i < 4; i++){

      posIFor = posI + movI[i], posJFor = posJ + movJ[i];

      if(posIFor >= 0 && posIFor < total && posJFor >= 0 && posJFor < total){

        currentDist = dists[posI][posJ] + matrix[posIFor][posJFor];

        if(currentDist < dists[posIFor][posJFor]){

          dists[posIFor][posJFor] = currentDist;
          Points.push({currentDist, posIFor, posJFor});

        }

      }

    }

  }

  return dists[total - 1][total - 1];
}
