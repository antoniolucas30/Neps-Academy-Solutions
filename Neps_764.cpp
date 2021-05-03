#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

struct Nickname{

  std::string nickName;
  long totalXP, lastMinute;

};

bool Compare(Nickname n1, Nickname n2);

int main(){

  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  std::vector <Nickname> vecNicks;
  long lenMap, maxMin, lastMessage, lenVec;
  std::string whatNick;
  bool found;

  std::cin >> lenMap >> maxMin;

  for(long i = 0; i < lenMap; i++){

    std::cin >> whatNick >> lastMessage;

    lenVec = vecNicks.size();
    found = false;

    for(long j = 0; j < lenVec; j++){

      if(vecNicks[j].nickName == whatNick){

        found = true;

        if(lastMessage >= (vecNicks[j].lastMinute + maxMin))
          vecNicks[j].totalXP += 25, vecNicks[j].lastMinute = lastMessage;

        break;

      }

    }

    if(!found)
      vecNicks.push_back({whatNick, 25, lastMessage});

  }

  std::sort(vecNicks.begin(), vecNicks.end(), Compare);
  lenVec = vecNicks.size();

  std::cout << "--Rank do Nepscord--\n";

  for(int i = 0; i < 3; i++){

    std::cout << '#' << i + 1 << '.';

    if(i < lenVec)
      std::cout << ' ' << vecNicks[i].nickName << " - Nivel " << (vecNicks[i].totalXP / 100) + 1;

    std::cout << '\n';

  }

  return 0;
}

bool Compare(Nickname n1, Nickname n2){

  if(n1.totalXP > n2.totalXP)
    return 1;

  else if(n1.totalXP == n2.totalXP && n1.nickName < n2.nickName)
    return 1;

  return 0;

}
