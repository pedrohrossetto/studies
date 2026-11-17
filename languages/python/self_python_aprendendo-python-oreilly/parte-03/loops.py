
condition = True
while condition:
    if not condition: # encerramento por break, não invoca o bloco else
        print("if break")
        break
    if condition: # encerramento natural invoca o bloco else
        print("if encerramento natural") 
        condition = False
else:
    print("Bloco else")


while True:
    name = input("Digite nome: ")
    if name == "break": break
    print(f"Olá, {name}!")



y = 123
x = y//2
while x > 1:
    w = y % x
    print(f"{y} % {x} = {w}")
    if w == 0:
        print(f"{y} has factor {x}")
        break
    x = x-1
else:
    print(f"{y} is prime")



y = 123

# Testamos divisores inteiros de 2 até a metade do número (inclusive)
for x in range(2, (y // 2) + 1):
    w = y % x
    print(f"{y} % {x} = {w}")
    if w == 0:
        print(f"{y} has factor {x}")
        break
else:
    # O else do 'for' funciona igual ao do 'while': só roda se não der 'break'
    print(f"{y} is prime")



itens = [1,2,3,4,5]
tests = [2,3,10]

for key in tests:
    for item in itens:
        print(f"{item} == {key}?")
        if item == key: 
            print(f"{key} was found!")
            break
    else: print(f"{key} was not found!")

itens = [1,2,3,4,5]
tests = [2,3,10]


for key in tests:
# O Python faz a busca interna para você de forma otimizada
    if key in itens:
        print(f"{key} was found!")
    else:
        print(f"{key} was not found!")



st1 = "spamcmm" 
st2 = "scam"
res = []

for x in st1:
    if x in st2: # vai buscar os caracteres em comum, independente de posição.
        res.append(x)

st1 = "spamcmm" 
st2 = "scam"
res = []

# O zip pareia os caracteres correspondentes: ('s','s'), ('p','c'), etc.
for letra1, letra2 in zip(st1, st2):
    if letra1 == letra2:
        res.append(letra1)
         
print(res)  # Saída: ['s', 'a', 'm']

# conversão de duas listas em um dicionario


chaves = ["a","b","c","d","e","f"]
valores = [1,2,3,4,5]
dicionario = dict(zip(chaves,valores))
dicionario



