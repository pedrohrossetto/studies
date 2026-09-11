import random

class ListaVetor:
    def __init__(self, tamanho):
        print(f"Inicializando a classe ListaVetor com parametro 'tamanho' = {tamanho} e 'self' = {self}")
        self.lista = self.criar_lista_aleatoria(tamanho)

    def criar_lista_aleatoria(self, tamanho):
        return [random.randint(1, 100) for _ in range(tamanho)]

    def ordenar_lista(self):
        for indice in range(0, len(self.lista)):
            indice_minimo = indice
            for indice_comparacao in range(indice + 1, len(self.lista)):
                if self.lista[indice_comparacao] < self.lista[indice_minimo]:
                    indice_minimo = indice_comparacao
            self.lista[indice_minimo], self.lista[indice] = self.lista[indice], self.lista[indice_minimo]
        return self.lista

if __name__ == "__main__":
    lista_vetor = ListaVetor(10)
    print("Lista original:", lista_vetor.lista)
    lista_ordenada = lista_vetor.ordenar_lista()
    print("Lista ordenada:", lista_ordenada)
