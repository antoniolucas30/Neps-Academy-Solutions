#include <iostream>
#include <vector>
#include <algorithm>

bool Compare(int n1, int n2);

int main(){

  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  std::string sequence;
  int lenStr;
  std::vector <int> LIS;

  std::cin >> sequence;

  lenStr = sequence.size();

  for(int i = 0; i < lenStr; i++){

    std::vector <int>::iterator it1 = std::lower_bound(LIS.begin(), LIS.end(), (sequence[i] - 'A'), Compare);

    if(it1 == LIS.end())
      LIS.push_back(sequence[i] - 'A');
    
    else
      (*it1) = sequence[i] - 'A';

  }

  std::cout << LIS.size() << std::endl;

  return 0;
}

bool Compare(int n1, int n2){
  
  return n1 <= n2;

}
