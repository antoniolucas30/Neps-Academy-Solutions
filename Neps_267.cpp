#include <iostream>
#include <vector>
#include <algorithm>

bool Compare(long n1, long n2);

int main(){

  int lenVec;
  long numX;
  std::vector <long> LIS;

  std::cin >> lenVec;

  for(int i = 0; i < lenVec; i++){

    std::cin >> numX;

    std::vector <long>::iterator itFind = std::lower_bound(LIS.begin(), LIS.end(), numX, Compare);

    if(itFind == LIS.end())
      LIS.push_back(numX);

    else
      (*itFind) = numX;

  }

  std::cout << LIS.size() << std::endl;

}

bool Compare(long n1, long n2){

  return n1 <= n2;

}
