#include <iostream>

using namespace std;

long tamanhoAtualizacoes;
long ultimoIndex = 1;
long long vetorSoma[200002];
long qntDias;
long precoDias;
long totalConsultas;
long diaInicio;
long diaFinal;

int main(){

  cin >> tamanhoAtualizacoes;

  for(long i = 0; i < tamanhoAtualizacoes; i++){

    cin >> qntDias >> precoDias;

    for(long j = 0; j < qntDias; j++){

      vetorSoma[ultimoIndex] = vetorSoma[ultimoIndex - 1] + precoDias;
      ultimoIndex++;

    }

  }

  cin >> totalConsultas;

  for(long i = 0; i < totalConsultas; i++){

    cin >> diaInicio >> diaFinal;

    cout << vetorSoma[diaFinal] - vetorSoma[diaInicio - 1] << '\n';

  }

  return 0;
}
