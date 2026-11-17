D = {}
D[1] = "A";D 
# como o dicionário não é sequencial, o acesso por [1] cria na verdade uma nova chave 1 com valor "A
# Qualquer objeto imutável pode ser uma chave de dicionário.
D[True] = "Sobrescreveu!";D
# Como bool é um subtipo de int, True e 1 são considerados a mesma chave
True is 1 # FALSO
True == 1 # Verdadeiro
D["novachave"] = 12314;D
# Assim como a primeira atribuição, chaves inexistentes quando atribuidas um valor são craidas no dicionário
