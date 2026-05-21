from abc import ABC, abstractmethod
from typing import TYPE_CHECKING

if TYPE_CHECKING:
    from missao import Missao

class EstadoMissao(ABC):
    def __init__(self, missao: 'Missao'):
        self._missao = missao 

    @abstractmethod
    def iniciar(self) -> bool:
        pass

    @abstractmethod
    def concluir(self) -> bool:
        pass


class EstadoPendente(EstadoMissao):
    def iniciar(self) -> bool:
        # Sucesso: Print enviado pelo estado correto
        print(f"▶️   Missão '{self._missao.nome}' iniciada com sucesso!") 
        from status import EstadoAndamento
        self._missao.definir_estado(EstadoAndamento(self._missao))
        return True

    def concluir(self) -> bool:
        # Erro: Print enviado pelo estado correto
        print(f"❌  Erro: Não é possível progredir em '{self._missao.nome}'. Ela ainda está Pendente!")
        return False


class EstadoAndamento(EstadoMissao):
    def iniciar(self) -> bool:
        print(f"⚠️  Aviso: A missão '{self._missao.nome}' já está em andamento.")
        return False

    def concluir(self) -> bool:
        # Aqui entraria sua lógica de checar se o objetivo foi batido. 
        # Vamos simular que bateu o objetivo para o exemplo:
        print(f"🏆  Missão '{self._missao.nome}' concluída com sucesso!")
        from status import EstadoConcluida
        self._missao.definir_estado(EstadoConcluida(self._missao))
        return True


class EstadoConcluida(EstadoMissao):
    def iniciar(self) -> bool:
        print(f"❌  Erro: '{self._missao.nome}' já foi concluída. Não pode ser reiniciada.")
        return False

    def concluir(self) -> bool:
        print(f"❌  Erro: Você já finalizou a missão '{self._missao.nome}'.")
        return False


class EstadoFracassada(EstadoMissao):
    def iniciar(self) -> bool:
        print("❌   Erro: A missão fracassou e não pode ser iniciada.")
        return False

    def concluir(self) -> bool:
        print("❌   Erro: Não é possível concluir uma missão fracassada.")
        return False