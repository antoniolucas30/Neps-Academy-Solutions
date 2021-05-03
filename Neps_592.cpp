#include <iostream>
#include <unordered_map>

int main(){

  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  std::unordered_map <char, int> Map;
  std::string phrase;
  int lenStr;

  Map['A'] = 2, Map['B'] = 2, Map['C'] = 2, Map['D'] = 3, Map['E'] = 3, Map['F'] = 3, Map['G'] = 4, Map['H'] = 4, Map['I'] = 4, Map['J'] = 5, Map['K'] = 5, Map['L'] = 5, Map['M'] = 6, Map['N'] = 6, Map['O'] = 6, Map['P'] = 7, Map['Q'] = 7, Map['R'] = 7, Map['S'] = 7, Map['T'] = 8, Map['U'] = 8, Map['V'] = 8, Map['W'] = 9, Map['X'] = 9, Map['Y'] = 9, Map['Z'] = 9;

  std::cin >> phrase;
  lenStr = phrase.length();

  for(int i = 0; i < lenStr; i++){

    if(phrase[i] >= 'A' && phrase[i] <= 'Z'){
  
      std::cout << Map[phrase[i]];
      continue;

    }

    std::cout << '-';

  }

  std::cout << '\n';

  return 0;
}
