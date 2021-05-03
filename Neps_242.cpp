#include <iostream>

using namespace std;

string title(string F){
	//Seu código aqui
  
  int tam = F.size();

  for(int i = 0; i < tam; i++){

    if(i == 0 || F[i - 1] == ' ')
      F[i] = std::toupper(F[i]);
    else
      F[i] = std::tolower(F[i]);

  }

  return F;
}

int main(){ 
	string F;

	getline(cin, F);

	cout << title(F) << "\n";
}

