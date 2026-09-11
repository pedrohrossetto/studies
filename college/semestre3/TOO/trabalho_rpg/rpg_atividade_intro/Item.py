from enum import Enum

class TipoItem(Enum):
    ARMA = ("Arma", "_ataque_vigente")
    VESTIMENTA = ("Vestimenta", "_protecao_fisica")
    UTILITARIO = ("Utilitário", "cura") # Exemplo extra

    def __init__(self, valor, atributo_alvo):
        self.__tipo_item = valor
        self.__atributo_alvo = atributo_alvo
        self.__nome_atributo = atributo_alvo.replace("_", " ").strip().title()
        
    @property
    def tipo_item(self):
        return self.__tipo_item
    
    @property
    def atributo_alvo(self):
        return self.__atributo_alvo
    
    @property
    def nome_atributo(self):
        return self.__nome_atributo



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
        print(f"\n--- {self.__nome} ---\n")
        print(f"Descrição: {self.__descricao}")
        # Aqui a mágica acontece: usamos o label do Enum
        print(f"{self.tipo.nome_atributo}: {self.valor_efeito}")
        print(f"Tipo: {self.tipo.tipo_item}\n")

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
            
            print(f"{self.__nome} aplicado! {self.__tipo.nome_atributo} aumentado para {novo_valor}.")

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
            
            print(f"{self.__nome} desaplicado! {self.__tipo.nome_atributo} reduzido para {novo_valor}.")

        except AttributeError:
            # Use AttributeError em vez de ValueError, pois o erro ocorrerá 
            # se o 'atributo_alvo' não existir no personagem.
            print(f"Erro: O personagem não possui o atributo '{self.__tipo.nome_atributo}'.")
        except Exception as e:
            print(f"Erro inesperado ao desaplicar: {e}")