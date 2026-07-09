S = "spam"
L = [1,2,3,4]
T = (1,2,3,4)
# o operador + é estrito e exige que ambos os operandos sejam do exato mesmo tipo de sequência.
S + T # Não funciona por que a string espera uma string
S + str(T) # estrutura da tupla permanece mas é concatenada com a string
S + "".join(map(str, T)) # concatena os valores da lista à string. 
# O método .map() aplique o método str a cada elemento de T e join junta todos os elementos que foram fragmentados
S + L # String tem que ser convertida antes para lista antes de ser concatenada com uma lista
list(S) + L # Agora funciona
S + str(L) # Concatena a lista na sua estrutura preservada à string
S + "".join(map(str, L)) # concatena os valores da lista à string. 
# O método .map() aplique o método str a cada elemento de L e join junta todos os elementos que foram fragmentados
S + S # Concatenamento funcionamento normalmente criando uma nova string
T + T # cria uma nova tupla com a concatenação das duas tuplas
T + L # não funciona por que os objetos precisam ser do mesmo tipo
T + tuple(L) #agora funciona
L + L # concatenação da lista em um novo objeto de tipo lista
T * 2 # duplica a tupla em novo objeto

S = "spam"
L = [1,2,3,4]
T = (1,2,3,4)
D = {"a":1,"b":2,"c":3}
D + L # Não funciona,os termos devem ser do mesmo tipo
L + list(D.keys())
list(D.values())
S_em_L = list(S)
#converte a string em lista e armazena o resultado
# converte o resultado em string novamente 
S_em_L.append("APPEND") # Altera a lista in-place
S_em_L 
S_em_L.append(("".join(map(str, L)))) # append "1234"
S_em_L 
S_em_L + L # "Append" da lista desempacotada dentro da lista em um novo objeto


S_em_L = S_em_L.append("APPEND") # ERRO! .append retorna None
S_em_L # retorna nada
print(S_em_L) # retorna None
S + "".join(map(str, L)) # faz a mesma coisa e é mais fácil

# O objeto fracionado é o mesmo do original
S[0:2] 
L[0:2]
T[0:2]

# 8. Indexação
S[0][0][0] 
# cada colchetes tenta acessar um índice dentro do colchete anterior
# Como uma string é uma coleção de caracteres, e em Python, não existe o tipo de dado "caractere individual" 
# cada caracter se torna uma string de um caracter.
# após acessar o primeiro caracter da string original,
# os demais estão reacessando o mesmo caracter que é o único índice disponível para acesso.
# se tentar acessar outro índice diferente de 0, irá retornar out of range

L[0][0][0]
# A mesma tentativa de acesso não irá funcionar em uma lista
#  se ela contiver dados não sequenciais na posição acessada
# exemplo: 1 é um int e não é acessado por colchetes então retorna erro