#include <iostream>

using namespace std;

char matrizVulcao[501][501];
int tamanho;
int poder;

void FloodFill(int posicaoAtualI, int posicaoAtualJ){

  if(posicaoAtualI < 0 || posicaoAtualI == tamanho || posicaoAtualJ < 0 || posicaoAtualJ == tamanho || (matrizVulcao[posicaoAtualI][posicaoAtualJ] - '0') > poder || matrizVulcao[posicaoAtualI][posicaoAtualJ] == '*')
    return;

  matrizVulcao[posicaoAtualI][posicaoAtualJ] = '*';

  FloodFill(posicaoAtualI - 1, posicaoAtualJ);
  FloodFill(posicaoAtualI + 1, posicaoAtualJ);
  FloodFill(posicaoAtualI, posicaoAtualJ - 1);
  FloodFill(posicaoAtualI, posicaoAtualJ + 1);

}

int main(){

  std::cin >> tamanho >> poder;

  for(int i = 0; i < tamanho; i++){

    for(int j = 0; j < tamanho; j++)
      std::cin >> matrizVulcao[i][j];

  }

  FloodFill(0, 0);

  for(int i = 0; i < tamanho; i++){

    for(int j = 0; j < tamanho; j++)
      std::cout << matrizVulcao[i][j];

    std::cout << '\n';

  }

  return 0;
}
