#include <iostream>
#include <unordered_set>

int main(){

  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  std::unordered_set <long> students;
  long lenSet, studentNum;

  std::cin >> lenSet;

  for(long i = 0; i < lenSet; i++){

    std::cin >> studentNum;
    students.insert(studentNum);

  }

  std::cout << students.size() << std::endl;

  return 0;
}
