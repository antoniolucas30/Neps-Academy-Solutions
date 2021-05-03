#include <iostream>
#include <iomanip> //precisão das casas decimais

using namespace std;

//declaração de variáveis
int diasPassados;
int quantasPlacas;
int diaMelhor = 1;
int diaPior = 1;

double moedasGeradas;
double valorMoeda[10002];
double quantidadeMoedasGeradas = 0;
double vendaAtual;
double melhorVenda;
double piorVenda;


int main(){

  cin >> diasPassados >> quantasPlacas;

  for(int i = 0; i < diasPassados; i++)
    cin >> valorMoeda[i]; //leitura dos valores

  for(int i = 0; i < diasPassados; i++){

    cin >> moedasGeradas; //leitura da quantidade de moedas geradas

    quantidadeMoedasGeradas += (moedasGeradas * quantasPlacas);

    vendaAtual = quantidadeMoedasGeradas * valorMoeda[i];

    if(i == 0)
      melhorVenda = vendaAtual, piorVenda = vendaAtual;

    else{

      if(vendaAtual > melhorVenda)
        melhorVenda = vendaAtual, diaMelhor = i + 1;

      if(vendaAtual < piorVenda)
        piorVenda = vendaAtual, diaPior = i + 1;

    }

  }

  cout << fixed << diaMelhor << ' ' << setprecision(2)  << melhorVenda << '\n' << setprecision(0)  << 
    diaPior << ' ' << setprecision(2)  << piorVenda << '\n';

  return 0;
}
