#include <iostream>

int direcX[] = {0, 1, 0, -1};
int direcY[] = {1, 0, -1, 0};

int main(){
  
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  long lines, columns, initialX, initialY, *vecX, *vecY, obstacles, number, currentDirec = 0;

  std::cin >> lines >> columns >> initialX >> initialY >> obstacles >> number;

  vecX = new long[obstacles], vecY = new long[obstacles];

  for(long i = 0; i < obstacles; i++)
    std::cin >> vecX[i] >> vecY[i];

  for(long i = 0; i < number; i++){

    bool obs = false;

    for(long j = 0; j < obstacles; j++){

      if(currentDirec == 0){

        if(initialX == vecX[j] && vecY[j] > initialY){

          obs = true;
          initialY = vecY[j] - 1;
          break;

        }

      }

      else if(currentDirec == 1){

        if(initialY == vecY[j] && vecX[j] > initialX){

          obs = true;
          initialX = vecX[j] - 1;
          break;

        }

      }

      else if(currentDirec == 2){

        if(initialX == vecX[j] && vecY[j] < initialY){

          obs = true;
          initialY = vecY[j] + 1;
          break;

        }

      }

      else{

        if(initialY == vecY[j] && vecX[j] < initialX){

          obs = true;
          initialX = vecX[j] + 1;
          break;

        }

      }
      
    }
    
    if(!obs){

      if(currentDirec == 0)
        initialY = columns;

      else if(currentDirec == 1)
        initialX = lines;

      else if(currentDirec == 2)
        initialY = 1;

      else
        initialX = 1;

    }

    currentDirec++;

    if(currentDirec == 4)
      currentDirec = 0;

  }

  std::cout << initialX << ' ' << initialY << '\n';

  return 0;
}
