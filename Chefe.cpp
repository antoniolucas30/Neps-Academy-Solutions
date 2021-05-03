#include <iostream>
#include <vector>

void AcharMenor(std::vector <std::vector <int>> &Grafo, bool *nodeNoCaminho, int nodeRequisitado, unsigned int *result, unsigned int *idades);

int main(){
  
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  unsigned int empregados, relacoes, instrucoes, *idades, nodeU, nodeV, result, tam;
  std::vector <std::vector <int>> GrafoGerenciado;
  bool *nodeNoCaminho;
  char pergunta;

  std::cin >> empregados >> relacoes >> instrucoes;
  GrafoGerenciado.resize(empregados);
  nodeNoCaminho = new bool[empregados];
  idades = new unsigned int[empregados];

  for(int i = 0; i < empregados; i++){

    std::cin >> idades[i];

  }

  for(unsigned int i = 0; i < relacoes; i++){

    std::cin >> nodeU >> nodeV;
    GrafoGerenciado[nodeV - 1].push_back(nodeU - 1);

  }

  for(int i = 0; i < instrucoes; i++){

    std::cin >> pergunta;

    if(pergunta == 'T'){

      std::cin >> nodeU >> nodeV;

      nodeU--, nodeV--;
      
      std::swap(GrafoGerenciado[nodeU], GrafoGerenciado[nodeV]);

      for(int j = 0; j < empregados; j++){

	tam = GrafoGerenciado[j].size();

	for(int k = 0; k < tam; k++){

	  if(GrafoGerenciado[j][k] == nodeU)
	    GrafoGerenciado[j][k] = nodeV;
	  else if(GrafoGerenciado[j][k] == nodeV)
	    GrafoGerenciado[j][k] = nodeU;

	}

      }

    }

    else if(pergunta == 'P'){

      result = -1;

      for(int j = 0; j < empregados; j++)
	nodeNoCaminho[j] = 0;

      std::cin >> nodeU;

      nodeU--; 
      AcharMenor(GrafoGerenciado, nodeNoCaminho, nodeU, &result, idades);

      if(result == -1)
	std::cout << '*' << std::endl;
      else
	std::cout << result << std::endl;

    }

  }

  return 0;
}

void AcharMenor(std::vector <std::vector <int>> &Grafo, bool *nodeNoCaminho, int nodeRequisitado, unsigned int *result, unsigned int *idades){

  int nodeAtual, tamNodeAtual = Grafo[nodeRequisitado].size();
  
  nodeNoCaminho[nodeRequisitado] = 1;

  for(int i = 0; i < tamNodeAtual; i++){

    nodeAtual = Grafo[nodeRequisitado][i];

    if(nodeNoCaminho[nodeAtual] == 0){

      if(*(result) == -1 || *(result) > idades[nodeAtual])
	*(result) = idades[nodeAtual];

      AcharMenor(Grafo, nodeNoCaminho, nodeAtual, result, idades);

    }

  }

}
