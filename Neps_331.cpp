#include <iostream>
#include <vector>

int main(){

  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  long lenTask, lenOp, nodeU, nodeV, *vec;
  std::vector <std::vector <long>> Graph;
  std::vector <long> result;
  bool flag = false;

  std::cin >> lenTask >> lenOp;

  vec = new long[lenTask]{0};
  Graph.resize(lenTask);

  for(long i = 0; i < lenOp; i++){

    std::cin >> nodeU >> nodeV;

    vec[nodeV]++;
    Graph[nodeU].push_back(nodeV);

  }

  for(long i = 0; i < lenTask; i++){

    flag = false;

    for(long j = 0; j < lenTask; j++){

      if(vec[j] == 0){

        flag = true;

        long lenNode = Graph[j].size();

        for(long k = 0; k < lenNode; k++){

          vec[Graph[j][k]]--;

        }

        vec[j] = -1;
        result.push_back(j);

        break;

      }

    }

    if(!flag)
      break;

  }

  if(!flag)
    std::cout << "*\n";

  else{

    for(long i = 0; i < lenTask; i++){

      std::cout << result[i] << '\n';

    }

  }

  return 0;
}
