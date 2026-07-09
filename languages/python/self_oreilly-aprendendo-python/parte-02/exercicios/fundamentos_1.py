
# Teste de Operações Básicas

## Tipos básicos

2 ** 16 # 2 elevado na 16
2 / 5, 2 / 5.0 # a , no meio faz com que seja criada uma tupla (0.4,0,4)
"spam" + "eggs" # vai concatenar as duas strings em uma nova strin "spameggs"
S = "ham" # atribuindo "ham" a S
"eggs" + S # Concatenando o conteudo de S com eggs em uma nova strign "eggsham"
S * 5 # Repeticao de S 5 vezes em um novo objeto string
S[:0] # String vazia indíce 0 (omitido) até 0 (não incluso)
('x',)[0] # acessando x (indice 0) da tupla criada após criação com (x,)
('x','y')[1] # acessando y (indice 1) da tupla criada após criação com (x,y)



## Listas

([1,2,3] + [4,5,6])[2:4] 
## uma nova lista com as duas listas é criada, 
# não é criada uma tupla por que não há "," após o primeiro termo (a lista)
# [2:4] acessa o índice 2 até o 3 (4 não incluso)

L = [1,2,3] + [5,4,6] # L será criado com uma lista só [1 ... 6]
L, L[:],L[:0],L[-2],L[-2:]
### L, exibe a lista toda, L[:] cópia de L, L[:0] lista vazia,
### L[-2] acessa o penúltimo índice, L[-2:] do penúltimo até o final
### A linha toda cria uma tupla com parenteses omitido
[L[2],L[3]] # cria uma nova lista com os índices 2 e 3 da lista L original
L.reverse(); L 
# L.reverse() inverte a lista inplace e retorna None. 
# O ";" serve para separar uma instrução em mesma linha de outra. L exibe a lista após inversão
L.sort(); L # L.sort() ordena a lista em ordem crescente
L.sort(reverse=True); L # L.sort(reverse=True) ordena a lista em ordem decrescente
L.index(1) # retorna o index do parametro (1), nesse caso retornará 0 pois é o 1° item


## Dicionarios


{'a':1,"b":2}['b'] # acessa a chave 'b' e retorna seu valor (2)

D = {'a':1,"b":2,"x":0, "dados":{"nome":"Pedro","idade":22}} # criação básica de um dicionário
D["a"] = 3;D # atribuição de valor à chave "a"
D["dados"]["nome"] = "Pedrao" # Atribuição de dados aninhados
D["a"]+D["b"] # soma os valores das duas chaves associadas -> 3
D[(1,2,3)] = 4; D 
# Cria uma nova entrada no dicionário com a tupla (1,2,3) como chave e 4 como valor

D.keys(), D.values(), (1,2,3) in D 
# 1. keys() retorna todas as chaves do dicionario, 
# 2. values() retorna todos os valores
# 3. (key) in dict retorna bool se a chave está presente ou não no dicionario.
#   antigo has_key(x) foi depreciado em favor desse novo formato


[[]][0] # Lista de um elemento com uma lista vazia
["", [], (), {}, None] # Lista de 5 elementos com uma string, lista, tupla, dicionario (vazios) e um valor None