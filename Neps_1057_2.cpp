#include <iostream>
#include <algorithm>

using namespace std;

long vetorResto[100002];
long tamanhoVetor;
long qualPosicao;
long Xi;
long Yi;

int main(){

  cin >> tamanhoVetor >> qualPosicao;

  for(long i = 0; i < tamanhoVetor; i++){

    cin >> Xi >> Yi;

    vetorResto[i] = (Xi % Yi);

  }

  sort(vetorResto, vetorResto + tamanhoVetor);

  cout << vetorResto[qualPosicao - 1] << '\n';

  return 0;
}
