#include <iostream>

long BinarySearch(long* vecFaixas, long* vecPremiacao, long leftIndex, long rightIndex, long force);

int main(){

  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  long totalFaixas, totalOgros, ogroI, *vecFaixas, *premiacao;

  std::cin >> totalFaixas >> totalOgros;

  vecFaixas = new long[totalFaixas];
  premiacao = new long[totalFaixas];

  vecFaixas[0] = 0;

  for(long i = 1; i < (totalFaixas); i++)
    std::cin >> vecFaixas[i];
  
  for(long i = 0; i < totalFaixas; i++)
    std::cin >> premiacao[i];

  for(long i = 0; i < totalOgros; i++){

    std::cin >> ogroI;

    if(i != 0)
      std::cout << ' ';

    std::cout << BinarySearch(vecFaixas, premiacao, 0, totalFaixas - 1, ogroI);

  }

  std::cout << std::endl;

  return 0;
}

long BinarySearch(long* vecFaixas, long* vecPremiacao, long leftIndex, long rightIndex, long force){

  long middle = (leftIndex + rightIndex) / 2;

  if(leftIndex == (rightIndex - 1)){

    if(vecFaixas[rightIndex] <= force)
      return vecPremiacao[rightIndex];
    
    else
      return vecPremiacao[leftIndex];

  }

  if(vecFaixas[middle] < force)
    return BinarySearch(vecFaixas, vecPremiacao, middle, rightIndex, force);
  
  else if(vecFaixas[middle] > force)
    return BinarySearch(vecFaixas, vecPremiacao, leftIndex, middle, force);

  else
    return vecPremiacao[middle];

}
