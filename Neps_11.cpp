#include <iostream>

using namespace std;

int N; //valor N da entrada
int numeroAtual; //numeros que irao para a entrada
int armazenaFatorial = 1; //armazenará o fatorial de N
int arrayResultado[9]; //array, com margem, para armazenar o resultado
int matrixQntVezes[9][9]; //matriz da quantidade de vezes que cada número apareceu em cada posição

int main(){

  cin >> N; //leio N

  for(int i = 2; i <= N; i++) //execução do fatorial
    armazenaFatorial *= i;

  for(int i = 0; i < armazenaFatorial - 1; i++){

    for(int j = 1; j <= N; j++){

      cin >> numeroAtual; //leio o numero

      matrixQntVezes[numeroAtual][j]++; //incremento na matriz, conforme descrito

    }

  }

  for(int i = 1; i <= N; i++){ //aqui, vou percorrer o meu matrixQntVezes para poder achar a resposta

    for(int j = 1; j <= N; j++){

      if(matrixQntVezes[i][j] == ((armazenaFatorial / N) - 1)){ //quando isso ocorrer, significa que, para a posição j,
                                                                //achei o meunumeral correspondente, ou seja, i
        arrayResultado[j] = i;
        break;  //como já achei a resposta para j, dou um break.

      }

    }

  }

  for(int i = 1; i <= N; i++){ //realizo o cout da minha resposta :D!

    if(i != 1)
      cout << ' ';

    cout << arrayResultado[i];

  }

  cout << '\n';

  return 0;
}
