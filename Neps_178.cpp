#include <iostream>

int main(){

  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int vec[6], result = 0, tmp;

  for(int i = 0; i < 6; i++)
    std::cin >> vec[i];

  tmp = vec[5] - vec[2];

  if(vec[5] < vec[2]){

    tmp = 60 - vec[2] + vec[5];
    vec[1]++;

  }

  result += (tmp * 60);
  tmp = vec[4] - vec[1];

  if(vec[1] > vec[4]){

    tmp = 24 - vec[1] + vec[4];
    vec[0]++;

  }

  result += (tmp * 3600) + ((vec[3] - vec[0]) * 24 * 3600);

  std::cout << result << '\n';

  return 0;
}
