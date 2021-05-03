//ralouim

#include <iostream>
#include <cmath>

long *DP

double DistanciaEntrePontos(int X1, int Y1, int X2, int Y2);

void Recursiva(int vecX[], int vecY[], int tamanho, int cordXatual, int cordYatual, long int *resultTotal, int distPercorrida, double distanciaMax, double (*DistFcn)(int, int, int, int));
int main(){

  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  
  int tamanho, cordXatual, cordYatual;
  long resultado = 0;
  double distanciaMax;

  std::cin >> tamanho;

  int vecX[tamanho], vecY[tamanho];
  DP = new int[tamanho];

  for(int i = 0; i < tamanho; i++){
    
    std::cin >> vecX[i] >> vecY[i];
    DP[i] = -1;

  }

  Recursiva(vecX, vecY, tamanho, 0, 0, &resultado, 0, -1, DistanciaEntrePontos);


  std::cout << resultado << std::endl;

  return 0;
}

double DistanciaEntrePontos(int X1, int Y1, int X2, int Y2){

  return std::sqrt(std::pow((Y2 - Y1), 2) + std::pow((X2 - X1), 2));

}

void Recursiva(int vecX[], int vecY[], int tamanho, int index, int cordXatual, int cordYatual, long int *resultTotal, int distPercorrida, double distanciaMax, double (*DistFcn)(int, int, int, int)){

  double distanciaAtual;

  if(distPercorrida > (*resultTotal))
    (*resultTotal) = distPercorrida;

  for(int i = 0; i < tamanho; i++){

    distanciaAtual = DistFcn(vecX[i], vecY[i], cordXatual, cordYatual);

    if(distanciaAtual != 0 && (distanciaAtual < distanciaMax || distanciaMax == -1)){

      Recursiva(vecX, vecY, tamanho, vecX[i], vecY[i], resultTotal, distPercorrida + 1, distanciaAtual, DistFcn);

    }

  }

}

