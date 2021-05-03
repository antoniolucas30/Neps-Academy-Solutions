#include <iostream>

int main(){

  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int total, result = 0, vecMoedas[] = {100, 50, 25, 10, 5, 1}, ans[6] = {0};

  std::cin >> total;

  for(int i = 0; i < 6; i++){

    result += (total / vecMoedas[i]);
    ans[i] += (total / vecMoedas[i]);

    total -= ((total / vecMoedas[i]) * vecMoedas[i]);

  }

  std::cout << result << '\n';

  for(int i = 0; i < 6; i++)
    std::cout << ans[i] << '\n';

  return 0;
}
