#include <iostream>

using namespace std;

int totalBornes;
int totalComandos;
int estacaoProxima;
int comandoAtual;
int posicaoAtual;
int resultado;

int main(){

  cin >> totalBornes >> totalComandos >> estacaoProxima;

  resultado = 0;
  posicaoAtual = 1;

  if(estacaoProxima == 1)
    resultado = 1;

  for(int i = 0; i < totalComandos; i++){

    cin >> comandoAtual;

    posicaoAtual += comandoAtual;

    if(posicaoAtual == 0)
      posicaoAtual = totalBornes;

    else if(posicaoAtual == (totalBornes + 1))
      posicaoAtual = 1;

    if(posicaoAtual == estacaoProxima)
      resultado++;

  }

  cout << resultado << '\n';

  return 0;
}
