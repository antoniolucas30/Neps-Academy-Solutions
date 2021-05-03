#include <iostream>

int main(){
  
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  long *arr, cheques, habitantes, totTrocado = 0, tot = 0, X, valor, Y;
  std::string result = "SN";

  std::cin >> cheques >> habitantes;

  arr = new long[habitantes]{0};

  for(long i = 0; i < cheques; i++){

    std::cin >> X >> valor >> Y;

    arr[X - 1] -= valor, arr[Y - 1] += valor, totTrocado += valor;

  }

  for(long i = 0; i < habitantes; i++){

    if(arr[i] > 0)
      tot += arr[i];

  }

  std::cout << result[tot == totTrocado] << '\n' << tot << std::endl;

  return 0;
}
