#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>

int main(){

  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int lenTeams, lenStudents;
  std::string currentStudent;
  long power;
  std::vector <std::pair <long, std::string>> VecStudents;
  std::vector <std::vector <std::string>> VecTeams;

  std::cin >> lenStudents >> lenTeams;

  VecTeams.resize(lenTeams);

  for(int i = 0; i < lenStudents; i++){

    std::cin >> currentStudent >> power;
    VecStudents.push_back(std::make_pair(power, currentStudent));

  }

  std::sort(VecStudents.begin(), VecStudents.end());

  for(int i = lenStudents - 1, j = 0; i >= 0; i--){

    VecTeams[j].push_back(VecStudents[i].second);
    j++;

    (j == lenTeams) ? j = 0 : j += 0;

  }

  for(int i = 0; i < lenTeams; i++){

    lenStudents = VecTeams[i].size();
    std::sort(VecTeams[i].begin(), VecTeams[i].end());

    std::cout << "Time " << i + 1 << '\n';

    for(int j = 0; j < lenStudents; j++)
      std::cout << VecTeams[i][j] << '\n';

    std::cout << '\n';

  }

  std::cout << std::flush;

  return 0;
}
