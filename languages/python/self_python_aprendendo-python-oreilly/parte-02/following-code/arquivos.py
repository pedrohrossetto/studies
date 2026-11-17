with open('arquivo.txt', 'r', encoding='utf-8') as arquivo:
     # abre o arquivo apenas dentro do bloco
    for linha in arquivo:
        print(linha.strip())

with open('arquivo.txt', 'r', encoding='utf-8') as arquivo:
     # abre o arquivo apenas dentro do bloco
    linhas = arquivo.readlines()
    print(f"Total de linhas: {len(linhas)}")
    print(f"Conteúdo da Primeira linha: {linhas[0]}")


## arquivo.read() ## read until EOF 
## arquivo.readline() # read until newline or EOF


## arquivo.close()
