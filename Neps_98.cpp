#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>

bool Compare(std::pair <int, int> P1, std::pair <int, int> P2);

int main(){

  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  bool flag, *vecBool;
  int maxNum, lenVec, num, totalVec = 0, diffNum = 0;
  std::vector <std::pair <int, int>> VecNums;

  std::cin >> maxNum >> lenVec;

  vecBool = new bool[maxNum + 1]{0};

  for(int i = 0; i < lenVec; i++){

    flag = true;

    std::cin >> num;

    vecBool[num] = 1;

    for(int j = 0; j < totalVec; j++){

      if(VecNums[j].first == num){

        VecNums[j].second++;
        flag = false;
        break;

      }

    }

    if(flag){
      
      VecNums.push_back(std::make_pair(num, 1));
      totalVec++;

    }

  }

  std::sort(VecNums.begin(), VecNums.end(), Compare);

  for(int i = 1; i < totalVec; i++){

    if(VecNums[i].second != VecNums[i - 1].second)
      diffNum++;

  }

  if(diffNum == 0){

    if(lenVec >= maxNum)
      std::cout << "*\n";

    else{

      for(int i = maxNum; i >= 1; i--){

        if(vecBool[i] == 0){

          std::cout << '+' << i << '\n';
          break;

        }

      }

    }

  }

  else if(diffNum > 2)
    std::cout << "*\n";

  else{

    if(VecNums[0].second == (VecNums[totalVec - 1].second - 1)){

      if(VecNums[0].second == VecNums[1].second)
        std::cout << '-' << VecNums[totalVec - 1].first << '\n';

      else
        std::cout << '+' << VecNums[0].first << '\n';

    }

    else if(VecNums[0].second == (VecNums[totalVec - 1].second - 2))
      std::cout << '-' << VecNums[totalVec - 1].first << " +" << VecNums[0].first << '\n';

    else
      std::cout << "*\n";

  }

  return 0;
}

bool Compare(std::pair <int, int> P1, std::pair <int, int> P2){

  return P1.second < P2.second;

}

