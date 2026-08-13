from abc import ABC
from typing import Any, Optional, TYPE_CHECKING, Type

if TYPE_CHECKING:
    from status import EstadoMissao

class Missao(ABC):
    def __init__(self, nome: str, descricao: str, recompensa: Any, status_classe: Optional[Type['EstadoMissao']] = None):
        self.__nome = nome
        self.__descricao = descricao
        self.__recompensa = recompensa
        
        from status import EstadoPendente
        classe_alvo = status_classe if status_classe is not None else EstadoPendente
        self.__status = classe_alvo(self)

    @property
    def nome(self):
        return self.__nome
    
    @nome.setter
    def nome(self, nome):
        if nome is None or not isinstance(nome, str):
            raise ValueError("Nome é obrigatório e deve ser uma string")
        nome_limpo = nome.strip()
        if not nome_limpo:
            raise ValueError("Nome não pode estar vazio ou conter apenas espaços")
        self.__nome = nome_limpo

    @property
    def descricao(self):
        return self.__descricao
    
    @descricao.setter
    def descricao(self, descricao):
        self.__descricao = descricao

    @property
    def recompensa(self):
        return self.__recompensa
    
    @recompensa.setter
    def recompensa(self, recompensa):
        if not isinstance(recompensa, (int, float)):
            raise ValueError("Recompensa deve ser um valor numérico")
        if recompensa < 1 or recompensa > 50:
            raise ValueError("Recompensa deve ser um valor positivo entre 1 e 50")
        self.__recompensa = recompensa

    @property
    def status(self):
        return self.__status
    
    @status.setter
    def status(self, status):
        self.__status = status
    
    def definir_estado(self, novo_estado):
        self.status = novo_estado
        
    def iniciar(self) -> bool:
        # Repassa para o estado e retorna o resultado booleano dele
        return self.status.iniciar()

    def concluir(self) -> bool:
        # Repassa para o estado e retorna o resultado booleano dele
        return self.status.concluir()
        
    def esta_concluida(self) -> bool:
        from status import EstadoConcluida
        # Ajustado para ler da propriedade pública 'status' para evitar erros de herança privada
        return isinstance(self.status, EstadoConcluida)

    def exibir_informacoes(self):
        print("\n")
        print(f"Missão [{self.__class__.__name__}]")
        print(f"Missão: {self.nome}")
        print(f"Descrição: {self.descricao}")
        print(f"Recompensa: {self.recompensa} XP")
        print(f"Status: {self.status.__class__.__name__}") # Mostra o nome da classe do estado

    def __str__(self):
        return f"Missão: {self.nome} | Descrição: {self.descricao} | Recompensa: {self.recompensa} XP | Status: {self.status.__class__.__name__}"

    def __eq__(self, outro):
        if not isinstance(outro, Missao):
            return False
        return (self.nome == outro.nome and 
                self.descricao == outro.descricao and 
                self.recompensa == outro.recompensa and 
                self.status == outro.status)


class MissaoCombate(Missao):
    # Ajustado: status_classe agora vem por último e é opcional (= None)
    def __init__(self, nome: str, descricao: str, recompensa: Any, inimigos_a_derrotar: int, inimigo: str, status_classe: Optional[Type['EstadoMissao']] = None):
        super().__init__(nome, descricao, recompensa, status_classe)
        self.__inimigos_a_derrotar = inimigos_a_derrotar
        self.__inimigo = inimigo 

    @property
    def valor_objetivo(self):
        return self.__inimigos_a_derrotar
    
    @valor_objetivo.setter
    def valor_objetivo(self, valor):
        if not isinstance(valor, int):
            raise ValueError("Deve ser um valor numérico")
        if valor < 1:
            raise ValueError("Deve ser um valor positivo")
        self.__inimigos_a_derrotar = valor

    @property
    def inimigo(self):
        return self.__inimigo
    
    @inimigo.setter
    def inimigo(self, valor):
        if isinstance(valor, str):
            self.__inimigo = valor.strip().title()    
        else: 
            raise ValueError("Deve ser um valor do tipo string")

    def exibir_informacoes(self):
        super().exibir_informacoes()
        print(f"Inimigo: {self.inimigo}")
        print(f"Quantidade a derrotar: {self.__inimigos_a_derrotar}")


class MissaoColeta(Missao):
    # Ajustado: status_classe agora vem por último e é opcional (= None)
    def __init__(self, nome: str, descricao: str, recompensa: Any, item_necessario: str, quantidade_item: int, status_classe: Optional[Type['EstadoMissao']] = None):
        super().__init__(nome, descricao, recompensa, status_classe)
        self.__item_necessario = item_necessario
        self.__quantidade_item = quantidade_item

    @property
    def valor_objetivo(self):
        return self.__quantidade_item
    
    @valor_objetivo.setter
    def valor_objetivo(self, quantidade_item):
        if not isinstance(quantidade_item, int):
            raise ValueError("Deve ser um valor numérico")
        if quantidade_item < 1:
            raise ValueError("Deve ser um valor positivo")
        self.__quantidade_item = quantidade_item

    @property
    def item_necessario(self):
        return self.__item_necessario
    
    @item_necessario.setter
    def item_necessario(self, item_necessario):
        if isinstance(item_necessario, str):
            self.__item_necessario = item_necessario.strip().title()    
        else: 
            raise ValueError("Deve ser um valor do tipo string")

    def exibir_informacoes(self):
        super().exibir_informacoes()
        print(f"Item a coletar: {self.__item_necessario}")
        print(f"Quantidade necessária: {self.__quantidade_item}")


class MissaoExploracao(Missao):
    # Ajustado: status_classe agora vem por último e é opcional (= None)
    def __init__(self, nome: str, descricao: str, recompensa: Any, local: str, distancia: float, tempo_limite: float, status_classe: Optional[Type['EstadoMissao']] = None):
        super().__init__(nome, descricao, recompensa, status_classe)
        self.local = local
        self.distancia = distancia
        self.tempo_limite = tempo_limite

    @property
    def local(self):
        return self.__local
    
    @local.setter
    def local(self, local):
        if not isinstance(local, str):
            raise ValueError("O local deve ser uma string")
        self.__local = local.strip().title()

    @property
    def valor_objetivo(self):
        return self.__distancia
    
    @valor_objetivo.setter
    def valor_objetivo(self, distancia):
        if not isinstance(distancia, (int, float)):
            raise ValueError("A distância deve ser um valor numérico")
        if distancia < 0:
            raise ValueError("A distância não pode ser negativa")
        self.__distancia = distancia

    @property
    def tempo_limite(self):
        return self.__tempo_limite
    
    @tempo_limite.setter
    def tempo_limite(self, tempo_limite):
        if not isinstance(tempo_limite, (int, float)):
            raise ValueError("O tempo limite deve ser um valor numérico")
        if tempo_limite <= 0:
            raise ValueError("O tempo limite deve ser maior que zero")
        self.__tempo_limite = tempo_limite

    def exibir_informacoes(self):
        super().exibir_informacoes()
        print(f"Localização a explorar: {self.local}")
        print(f"Distância a percorrer: {self.distancia} km")
        print(f"Tempo limite: {self.tempo_limite} horas")