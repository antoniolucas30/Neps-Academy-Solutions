#include <iostream>
#include <algorithm> //biblioteca para o sort

using namespace std;

//declaração de variáveis
int numCompetidores;
int vagasPreenchidas;
int arrPontuacao[1001];

//função necessária para meu sort ordenar de modo decrescente
bool Compare(int n1, int n2){

  return n2 < n1;

}

int main(){

  cin >> numCompetidores >> vagasPreenchidas;

  for(int i = 0; i < numCompetidores; i++)
    cin >> arrPontuacao[i];

  sort(arrPontuacao, arrPontuacao + numCompetidores, Compare); //ordenação

  while(vagasPreenchidas < numCompetidores && arrPontuacao[vagasPreenchidas] == arrPontuacao[vagasPreenchidas - 1])
    vagasPreenchidas++; //incremento da variável

  cout << vagasPreenchidas << '\n';

  return 0;
}
