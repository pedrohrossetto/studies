S = "spam"
S = S[0]+"l"+S[2:] # método por fatiamento e concatenação
S

S = "spam"
S = f"{S[0]}l{S[2:]}"  # 'slam' via fstring, mais legivel

S = "spam"

# 1. Converte para lista
L = list(S)       # ['s', 'p', 'a', 'm']

# 2. Aqui a atribuição por índice FUNCIONA porque a lista é mutável!
L[1] = "l"        # ['s', 'l', 'a', 'm']

# 3. Junta de volta em string
S = "".join(L)    # 'slam'