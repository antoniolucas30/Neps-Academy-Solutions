#include <iostream>
#include <algorithm>
#include <vector>

bool Compare(int n1, int n2);

int main(){

  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  std::string S1;
  int lenS1, currentNum;
  std::vector <int> LIS;

  std::cin >> S1;

  lenS1 = S1.size();

  for(int i = 0; i < lenS1; i++){

    currentNum = S1[i] - 'A';
    
    std::vector <int>::iterator it1 = std::lower_bound(LIS.begin(), LIS.end(), currentNum, Compare);

    if(it1 == LIS.end())
      LIS.push_back(currentNum);

    else
      (*it1) = currentNum;
    

  }

  std::cout << LIS.size() << std::endl;

  return 0;
}

bool Compare(int n1, int n2){

  return n1 <= n2;

}
