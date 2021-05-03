#include <iostream>
#include <algorithm>

int main(){

  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int vec[10], num, i = 0, j = 9, middle;
  std::string result[] = {"NAO", "SIM"};
  bool ans = false;

  for(int i = 0; i < 10; i++)
    std::cin >> vec[i];

  std::sort(vec, vec + 10);

  std::cin >> num;

  while(i <= j){

    middle = (i + j) / 2;

    if(vec[middle] == num){

      ans = true;
      break;

    }

    else if(vec[middle] < num)
      i = middle + 1;

    else
      j = middle - 1;

  }

  std::cout << result[ans] << '\n';

  return 0;
}
