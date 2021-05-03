#include <iostream>

using namespace std;

int figurinhaAtual;
int totalFigurinhas;
int figurinhasCompradas;
int vetorFigurinhas[101]; //por ser declarado como global,
                          //terá todos seus valores definidos como 0

int main(){

  cin >> totalFigurinhas >> figurinhasCompradas;

  for(int i = 0; i < figurinhasCompradas; i++){

    cin >> figurinhaAtual;

    if(vetorFigurinhas[figurinhaAtual] == 0){

      vetorFigurinhas[figurinhaAtual] = 1;
      totalFigurinhas -= 1;

    }

  }

  cout << totalFigurinhas << '\n';

  return 0;
}
