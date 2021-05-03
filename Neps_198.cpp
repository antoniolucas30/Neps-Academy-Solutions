#include <iostream>

int main(){

  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int vecLines[3] = {0}, vecCols[3] = {0}, d1 = 0, d2 = 0, ans, num;
  std::string result[] = {"NAO", "SIM"};

  for(int i = 0; i < 3; i++){

    for(int j = 0; j < 3; j++){

      std::cin >> num;

      vecLines[i] += num;
      vecCols[j] += num;

      if(i == j)
        d1 += num;

      if((i + j) == 2)
        d2 += num;

    }

    if(i == 0)
      ans = vecLines[i];

  }

  std::cout << result[ans == vecLines[1] && ans == vecLines[2] && ans == vecCols[0] && ans == vecCols[1] && ans == vecCols[2] && ans == d1 && ans == d2] << '\n';

  return 0;
}
