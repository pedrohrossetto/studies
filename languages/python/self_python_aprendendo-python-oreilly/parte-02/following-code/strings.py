import sys
print(f"sys: {sys.argv}")

a = "teste"
print(a.replace("t","l"))
print(a.split("s"))
print("t" in a)
b = "a\nb\tc"
print(b)
print(len(b))


print("""

Título do meu livro
      

      conteudo do meu livro


      teste











      teste final

      """)

myfile = open(r"script_test","r")
for line in myfile:
    print(line)
    print(len(line))


indice = 0
print(a[::-1])

for letra in a: 
    print(a[0:indice])
    indice+=1

try:    
    a[0] = "L"
except Exception as e:
    print(f"{e}: Erro em alterar objeto string (imutável)")

alist = [1,2,3,4]
alist2 = alist * 2
print(alist2)