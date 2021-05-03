#include <iostream>
#include <queue>

using namespace std;

int numero;
int competidor1;
int competidor2;
int indexAtual = 0;
int quantiaComparacoes= 8;
bool flagAchei = false;
queue <int> filaCompetidores;
string resultado[] = {"oitavas", "quartas", "semifinal", "final"};

int main(){

  for(int i = 0; i < 16; i++){

    cin >> numero;
    filaCompetidores.push(numero);

  }

  while(indexAtual <= 3 && !flagAchei){

    for(int i = 0; i < quantiaComparacoes; i++){

      competidor1 = filaCompetidores.front();
      filaCompetidores.pop();
      competidor2 = filaCompetidores.front();
      filaCompetidores.pop();

      if((competidor1 == 9 && competidor2 == 1) || (competidor1 == 1 && competidor2 == 9)){

        cout << resultado[indexAtual] << '\n';
        flagAchei = true;
        
        break;

      }

      else if(competidor1 == 1 || competidor2 == 1)
        filaCompetidores.push(1);
      
      else if(competidor1 == 9 || competidor2 == 9)
        filaCompetidores.push(9);
      
      else
        filaCompetidores.push(competidor1);

    }

    indexAtual++;
    quantiaComparacoes /= 2;

  }

  return 0;
}