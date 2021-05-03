#include <iostream>

int main(){

  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n1, n2;
  double felix, marzia;

  std::cin >> n1 >> n2;

  felix = ((n1 + n2) * 70) / 2.0, marzia = ((320 - n1 - n2) * 70) / 2.0;

  if(felix > marzia)
    std::cout << "1\n";

  else if(felix < marzia)
    std::cout << "2\n";

  else
    std::cout << "0\n";

  return 0;
}
