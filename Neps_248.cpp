#include <iostream>

struct Horarios{

  long inicio, termino;

};

int main(){

  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int total;
  Horarios currentHorario, lastHorario;
  long horaInicio, horaTermino, result = 1;

  std::cin >> total;


  for(int i = 0; i < total; i++){

    std::cin >> horaInicio >> horaTermino;
    currentHorario = {horaInicio, horaTermino};

    if(i != 0){

      if(currentHorario.inicio >= lastHorario.inicio && currentHorario.inicio < lastHorario.termino){

        if(lastHorario.termino > currentHorario.termino)
          lastHorario = currentHorario;

      }

      else if(currentHorario.inicio >= lastHorario.termino){

        result++;
        lastHorario = currentHorario;

      }

    }

    else
      lastHorario = currentHorario;

  }

  std::cout << result << std::endl;


  return 0;
}
