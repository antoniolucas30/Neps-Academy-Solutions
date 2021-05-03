#include <iostream>

int movI[] = {0, 0, -1, 1};
int movJ[] = {-1, 1, 0, 0};

void FindPos(char **vec, int totalI, int totalJ, int* currentI, int* currentJ, bool** inPath);

int main(){

  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int rows, cols, posI, posJ;
  char **vec;
  bool **posInPath;

  std::cin >> rows >> cols;

  vec = new char*[rows];
  posInPath = new bool*[rows];

  for(int i = 0; i < rows; i++){

    vec[i] = new char[cols];
    posInPath[i] = new bool[cols]{0};

    for(int j = 0; j < cols; j++){

      std::cin >> vec[i][j];

      if(vec[i][j] == 'o')
        posI = i, posJ = j;

    }

  }

  FindPos(vec, rows, cols, &posI, &posJ, posInPath);

  std::cout << posI + 1 << ' ' << posJ + 1 << std::endl;

  return 0;
}

void FindPos(char **vec, int totalI, int totalJ, int* currentI, int* currentJ, bool** inPath){

  bool found = true;

  while(found){

    found = false;

    for(int i = 0; i < 4; i++){

      if((*currentI) + movI[i] >= 0 && (*currentI) + movI[i] < totalI && (*currentJ) + movJ[i] >= 0 && (*currentJ) + movJ[i] < totalJ && vec[(*currentI) + movI[i]][(*currentJ) + movJ[i]] == 'H' && inPath[(*currentI) + movI[i]][(*currentJ) + movJ[i]] == false){

        (*currentI) += movI[i], (*currentJ) += movJ[i];
        inPath[*currentI][*currentJ] = true;
        found = true;

        break;

      }

    }


  }

}
