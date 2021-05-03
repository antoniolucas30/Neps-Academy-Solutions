#include <iostream>
#include <queue>

int main(){

  int lenFila, num;
  std::priority_queue <int> fila;

  std::cin >> lenFila;

  for(int i = 0; i < lenFila; i++){

    std::cin >> num;

    fila.push(num);

  }

  while(!fila.empty()){
  
    std::cout << fila.top() << std::endl;

    fila.pop();

  }

  return 0;
}
