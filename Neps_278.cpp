#include <iostream>
#include <unordered_set>
#include <algorithm>

int main(){
  
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  long alice, bia, len1, len2, lenFinal2, num;
  std::unordered_set <long> set1, set2;

  std::cin >> alice >> bia;

  for(long i = 0; i < alice; i++){

    std::cin >> num;
    set1.insert(num);

  }

  for(long i = 0; i < bia; i++){

    std::cin >> num;
    set2.insert(num);

  }

  std::unordered_set <long>::iterator it = set2.begin();

  len1 = set1.size(), len2 = set2.size();
  lenFinal2 = len2;

  for(int i = 0; i < lenFinal2; i++, it++){
  
    if(std::find(set1.begin(), set1.end(), *it) != set1.end())
      len1--, len2--;

  }

  if(len2 < len1)
    std::cout << len2 << std::endl;

  else
    std::cout << len1 << std::endl;


  return 0;
}
