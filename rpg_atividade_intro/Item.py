from enum import Enum

class TipoItem(Enum):
    ARMA = ("ARMA", "_ataque_vigente")
    VESTIMENTA = ("VESTIMENTA", "_protecao_fisica")
    UTILITARIO = ("UTILITARIO", "cura") # Exemplo extra

    def __init__(self, valor, atributo_alvo):
        self._value_ = valor
        self.atributo_alvo = atributo_alvo



class Item:
    def __init__(self, nome, descricao, valor_efeito, tipo: TipoItem):
        self.__nome = nome
        self.__descricao = descricao
        self.__valor_efeito = valor_efeito
        # Garantimos que tipo seja a instância do Enum, não apenas a string
        self.__tipo = tipo 
    
    @property
    def nome(self):
        return self.__nome
    
    @property
    def descricao(self):
        return self.__descricao
    
    @property
    def valor_efeito(self):
        return self.__valor_efeito

    @property
    def tipo(self):
        return self.__tipo

    def exibir_informacoes(self):
        print(f"--- {self.__nome} ---")
        print(f"Descrição: {self.__descricao}")
        # Aqui a mágica acontece: usamos o label do Enum
        print(f"{self.tipo.atributo_alvo}: {self.valor_efeito}")
        print(f"Tipo: {self.tipo.value}\n")

    def aplicar_ao_personagem(self, personagem):
        try:
            if self.__tipo == TipoItem.UTILITARIO:
                pass  # Lógica específica se houver
            
            # 1. Pegamos o valor atual do atributo dinamicamente
            valor_atual = getattr(personagem, self.__tipo.atributo_alvo)
            
            # 2. Calculamos o novo valor
            novo_valor = valor_atual + self.__valor_efeito
            
            # 3. Atualizamos o atributo no personagem dinamicamente
            setattr(personagem, self.__tipo.atributo_alvo, novo_valor)
            
            print(f"{self.__nome} aplicado! {self.__tipo.atributo_alvo} aumentado para {novo_valor}.")

        except AttributeError:
            # Use AttributeError em vez de ValueError, pois o erro ocorrerá 
            # se o 'atributo_alvo' não existir no personagem.
            print(f"Erro: O personagem não possui o atributo '{self.__tipo.atributo_alvo}'.")
        except Exception as e:
            print(f"Erro inesperado ao aplicar: {e}")


    def desaplicar(self, personagem):
        try:
            if self.__tipo == TipoItem.UTILITARIO:
                pass  # Lógica específica se houver
            
            # 1. Pegamos o valor atual do atributo dinamicamente
            valor_atual = getattr(personagem, self.__tipo.atributo_alvo)
            
            # 2. Calculamos o novo valor
            novo_valor = valor_atual - self.__valor_efeito
            
            # 3. Atualizamos o atributo no personagem dinamicamente
            setattr(personagem, self.__tipo.atributo_alvo, novo_valor)
            
            print(f"{self.__nome} desaplicado! {self.__tipo.atributo_alvo} reduzido para {novo_valor}.")

        except AttributeError:
            # Use AttributeError em vez de ValueError, pois o erro ocorrerá 
            # se o 'atributo_alvo' não existir no personagem.
            print(f"Erro: O personagem não possui o atributo '{self.__tipo.atributo_alvo}'.")
        except Exception as e:
            print(f"Erro inesperado ao desaplicar: {e}")