#include <iostream>

void BFS(int **matrix, bool **inPath, int total, int posI, int posJ, int* result);

int movI[] = {0, 1, 0, -1};
int movJ[] = {1, 0, -1, 0};

int main(){

  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int num, posI, posJ, **matrix, result = 0;
  bool** inPath;

  std::cin >> num >> posI >> posJ;

  matrix = new int*[num];
  inPath = new bool*[num];

  for(int i = 0; i < num; i++){

    matrix[i] = new int[num];
    inPath[i] = new bool[num]{0};

    for(int j = 0; j < num; j++)
      std::cin >> matrix[i][j];

  }

  BFS(matrix, inPath, num, posI - 1, posJ - 1, &result);
  std::cout << result << std::endl;

  return 0;
}

void BFS(int **matrix, bool **inPath, int total, int posI, int posJ, int* result){

  int posIFOR, posJFOR;
  inPath[posI][posJ] = 1;
  (*result)++;

  for(int i = 0; i < 4; i++){

    posIFOR = posI + movI[i], posJFOR = posJ + movJ[i];

    if(posIFOR >= 0 && posIFOR < total && posJFOR >= 0 && posJFOR < total && inPath[posIFOR][posJFOR] == 0 && matrix[posI][posJ] <= matrix[posIFOR][posJFOR]){

      BFS(matrix, inPath, total, posIFOR, posJFOR, result);

    }

  }

}
