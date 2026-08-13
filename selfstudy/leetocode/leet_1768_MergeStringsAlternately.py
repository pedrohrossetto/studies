word1 = "abc"
word2 = "pqrasda"

def mergeAlternately(w1: str, w2: str) -> str:
    resultado = []
    i, j = 0, 0

    # Roda enquanto houver letras em pelo menos uma das strings
    while i < len(w1) or j < len(w2):
        if i < len(w1):
            resultado.append(w1[i])
            i += 1
        if j < len(w2):
            resultado.append(w2[j])
            j += 1

    return "".join(resultado)


resultado = mergeAlternately(word1, word2)
print(resultado)  # Saída esperada: "apbqcr"
