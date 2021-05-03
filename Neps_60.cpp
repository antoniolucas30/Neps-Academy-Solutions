#include <iostream>

int main(){

  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  long num, finalNum, *prefix, currentIndex, result = 0, indexLeft, indexRight, indexMiddle, mult, sumTotal;
  int numArr;

  std::cin >> num >> finalNum;

  prefix = new long[num];

  for(long i = 0; i < num; i++){

    std::cin >> numArr;

    if(i == 0)
      prefix[i] = numArr;

    else
      prefix[i] = prefix[i - 1] + numArr;

  }

  currentIndex = num - 1;

  while(currentIndex >= 0 && prefix[currentIndex] >= finalNum){

    if(prefix[currentIndex] == finalNum){

      result++;
      break;

    }

    else{

      indexLeft = 0, indexRight = currentIndex;

      while(indexLeft <= indexRight){
      
        indexMiddle = (indexLeft + indexRight) / 2;

        if(indexLeft == indexRight){

          if(indexLeft == 0)
            mult = prefix[0] * 2;

          else
            mult = (prefix[indexLeft] - prefix[indexLeft - 1]) * 2;

          if(mult == finalNum){

            result++;
            break;

          }

        }

        if(prefix[currentIndex] - prefix[indexMiddle] == finalNum){

          result++;
          break;

        }

        else if(prefix[currentIndex] - prefix[indexMiddle] > finalNum)
          indexLeft = indexMiddle + 1;
        
        else
          indexRight = indexMiddle - 1;
        
      }

      currentIndex--;

    }

  }

  currentIndex = num - 1;

  while(currentIndex > 0 && prefix[currentIndex] >= finalNum){

    for(int i = currentIndex - 1; i >= 0; i--){

      if(currentIndex == num - 1)
        sumTotal = (prefix[currentIndex] - prefix[currentIndex - 1]) * 2;

      else
        sumTotal = prefix[num - 1] - prefix[currentIndex - 1];

      if(i == 0)
        sumTotal += (prefix[i]) * 2;

      else
        sumTotal += (prefix[i]);

      if(sumTotal == finalNum)
        result++;

    }

    currentIndex--;


  }

  std::cout << result << std::endl;

  return 0;
}
