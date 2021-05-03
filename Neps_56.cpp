#include <iostream>

int main(){

  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  bool flag = true;
  std::string phrase, ans = "NS";
  int lenPhrase, totalBracket = 0, totalLines;

  std::cin >> totalLines;
  std::cin.ignore();

  for(int i = 0; i < totalLines; i++){

    std::getline(std::cin, phrase);
    lenPhrase = phrase.length();

    for(int j = 0; j < lenPhrase; j++){

      if(phrase[j] == '{')
        totalBracket++;

      else if(phrase[j] == '}')
        totalBracket--;

      if(totalBracket < 0)
        flag = false;

    }

  }

  if(totalBracket > 0)
    flag = false;

  std::cout << ans[flag] << '\n';

  return 0;
}
