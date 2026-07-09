L = [1,2,3,4]
L[4] # irá retornar erro por que o índice não existe
L[:4] # irá funcionar retornar até o último índice
L[:4:-1] 
# irá fazer passo negativo L[incio:fim:passo] assim assumirá o final da lista como inicio
# ficando L[3:4:-1], o que retornará uma lista vazia pois o fim já foi alcançado (está à direita do início.
L[-10000:10] 
# irá retornar os índices que existem normalmente
# Se inicio < 0, ele é forçado para 0
# Se fim > N, ele é forçado para N.
L[3:1]
# O fatiamento é interrompido antes de começar por que o fim já foi alcançado
# início (3) > fim (1)
L[3:1:-1] # Agora funciona
L = [1,2,3,4]
L[3:1] = ["?"]; L # assim é acessado no índice de início (3) e o novo valor assume a posição.
# É necessário [[]], colchetes duplos para criar lista dentro de list por que o python desempacota o primeiro nível de colchetes
L = [1,2,3,4];L[2] = [];L 
# Uma lista vazia é atribuída ao índice selecionado
# aqui não ocorre desempacotamente, isso só ocorre com atribuição por lista[inicio:fim]


L = [1,2,3,4];L[0:2] = [];L #substitui o intervalo por vazio (elimina)
L = [1,2,3,4];L[0:2] = 1;L # retorna erro por que o valor inserido deve ser sequencial
L = [1,2,3,4];L[0:2] = "string";L # irá desempacotar a string por caracacter
L = [1,2,3,4];L[0:2] = "string longa";L # irá desempacotar a string por caracacter e o espaço será um caracter também
L = [1,2,3,4];L[0:2] = [1];L # irá desempacotar o [1] e o 1 irá substituir o intervalo
L = [1,2,3,4];del L[0:2];L # irá excluir o intervalo