#include <iostream>

long soma(long* vec, long index);

int main(){

  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  long lenVec, *vecSum, *vec, index, oldValue, lenOp, op, num1, num2, num3;

  std::cin >> lenVec >> lenOp;

  vecSum = new long[lenVec + 1]{0}, vec = new long[lenVec];

  for(long i = 0; i < lenVec; i++){

    std::cin >> vec[i];

    index = i + 1;

    while(index <= lenVec){

      vecSum[index] += vec[i];
      index += (index & -index);

    }

  }


  for(long i = 0; i < lenOp; i++){

    std::cin >> op;

    if(op == 1){
      
      std::cin >> num1 >> num2 >> num3;

      if(num1 <= num2){

        for(long j = num1; j <= num2; j++){

          index = j;

          while(index <= lenVec){


            vecSum[index] -= vec[j - 1];
            vecSum[index] += num3;

            index += (index & -index);

          }


          vec[j - 1] = num3;

        }   
      
      }

    }

    else{

      std::cin >> num1 >> num2;

      num3 = 0;

      if(num1 > num2)
        std::cout << 0 << '\n';

      else{

        std::cout << soma(vecSum, num2) - soma(vecSum, num1 - 1) << '\n';

      }

    }

  }

  return 0;
}

long soma(long* vec, long index){

  long result = 0;

  while(index > 0){

    result += vec[index];
    index -= (index & -index);

  }

  return result;

}
