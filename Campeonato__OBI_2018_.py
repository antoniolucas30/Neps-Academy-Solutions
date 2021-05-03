filaCompetidores = []
listaResultado = ["oitavas", "quartas", "semifinal", "final"]
competidor1 = 0
competidor2 = 0
indexAtual = 0
flagAchei = False
quantidadeComparacoes = 8

filaCompetidores = list(map(int, input().split()))

while(indexAtual <= 3 and flagAchei == False):

  for i in range(0, quantidadeComparacoes):

    competidor1 = filaCompetidores[0]
    filaCompetidores.pop(0)
    competidor2 = filaCompetidores[0]
    filaCompetidores.pop(0)

    if((competidor1 == 9 and competidor2 == 1) or (competidor1 == 1 and competidor2 == 9)):

      print(listaResultado[indexAtual])
      flagAchei = True

      break

    elif(competidor1 == 1 or competidor1 == 9):

      filaCompetidores.append(competidor1)
    
    elif(competidor2 == 1 or competidor2 == 9):

      filaCompetidores.append(competidor2)

    else:

      filaCompetidores.append(competidor1)
    
  indexAtual += 1
  quantidadeComparacoes = int(quantidadeComparacoes / 2)
