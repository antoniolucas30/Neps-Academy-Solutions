#include <iostream>

using namespace std;

bool eh_primo(int x){
	//Seu código aqui.
  
  bool result = true;

  for(long int i = 2; i <= (x - 1); i++){

    if((x % i) == 0){

      result = false;
      break;

    }

  }

  if(x == 1)
    result = false;


  return result;

}

int main(){
	int x;

	cin>>x;

	if(eh_primo(x)){
		cout << "S" << "\n";
	}else{
		cout << "N" << "\n";
	}
}
