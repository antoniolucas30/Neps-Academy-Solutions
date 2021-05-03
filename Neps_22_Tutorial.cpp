#include <iostream>

using namespace std;

int matriz[101][101];
int tamanhoMatriz;
int soma;

int main(){

  cin >> tamanhoMatriz;

  for(int i = 0; i < tamanhoMatriz; i++){

    for(int j = 0; j < ; j++)
      cin >> matriz[i][j];

  }

  for(int i = 1; i < tamanhoMatriz; i++){

    for(int j = 1; j < tamanhoMatriz; j++){

      soma = matriz[i - 1][j] + matriz[i][j - 1] + matriz[i - 1][j - 1];

      if(soma <= 1)
        matriz[i][j] = 1;

      else
        matriz[i][j] = 0;

    }

  }

  std::cout << matriz[tamanhoMatriz - 1][tamanhoMatriz - 1] << '\n';

  return 0;
}

