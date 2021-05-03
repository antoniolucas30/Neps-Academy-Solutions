#include <iostream>
#include <unordered_map>

int main(){

  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  long lenDict;
  int testCases, lenLetra, tamStr;
  std::string palavra, traducao, sentenca;
  std::unordered_map <std::string, std::string> MapDict;

  std::cin >> testCases;

  for(int i = 0; i < testCases; i++){

    std::cin >> lenDict >> lenLetra;

    for(long j = 0; j < lenDict; j++){

      std::cin >> palavra;

      std::cin.ignore();
      std::getline(std::cin, traducao);

      MapDict[palavra] = traducao;

    }

    for(int j = 0; j < lenLetra; j++){

      std::getline(std::cin, palavra);
      tamStr = palavra.size();

      for(int k = 0, l = 0; k < tamStr; k++){

        if(palavra[k] == ' ' || k == tamStr - 1){

          sentenca = palavra.substr(l, k - l + (k == (tamStr - 1)));

          if(MapDict.find(sentenca) != MapDict.end())
            std::cout << MapDict[sentenca];

          else
            std::cout << sentenca;

          if(k != tamStr - 1)
            std::cout << ' ';

          l = k + 1;

        }

      }

      std::cout << '\n';

    }

    std::cout << '\n';

    MapDict.clear();

  }

  return 0;
}
