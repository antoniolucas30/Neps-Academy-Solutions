#include <iostream>

int Find(int studentFind, int *vecStudents);
void Union(int student1, int student2, int *vecStudents, int *totalFather);

int main(){

  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int *vecStudents, *totalFather, *ans, totalStudents, lines, student1, student2, father, result = 0;

  std::cin >> totalStudents >> lines;

  vecStudents = new int[totalStudents], totalFather = new int[totalStudents]{0}, ans = new int[totalStudents]{0};

  for(int i = 0; i < totalStudents; i++)
    vecStudents[i] = i;

  for(int i = 0; i < lines; i++){

    std::cin >> student1 >> student2;

    student1--, student2--;

    Union(student1, student2, vecStudents, totalFather);

  }

  for(int i = 0; i < totalStudents; i++){

    father = Find(i, vecStudents);

    if(ans[father] == 0)
      result++;

    ans[father] = 1;

  }

  std::cout << result << '\n';

  return 0;
}

int Find(int studentFind, int *vecStudents){

  if(vecStudents[studentFind] == studentFind)
    return studentFind;

  return vecStudents[studentFind] = Find(vecStudents[studentFind], vecStudents);

}

void Union(int student1, int student2, int *vecStudents, int *totalFather){

  int p1 = Find(student1, vecStudents), p2 = Find(student2, vecStudents);

  if(p1 == p2)
    return;

  if(totalFather[p1] > totalFather[p2])
    vecStudents[p2] = p1;

  else if(totalFather[p2] > totalFather[p1])
    vecStudents[p1] = p2;

  else{

    vecStudents[p2] = p1;
    totalFather[p1]++;

  }

}
