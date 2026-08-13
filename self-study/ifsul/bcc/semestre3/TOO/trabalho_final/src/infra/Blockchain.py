import hashlib
import json
from datetime import datetime
from typing import Optional, List, Dict

# Assumindo que a classe EventoLogistico abstrata está no caminho correto
from src.application.events.EventosBase import EventoLogistico 
# (Ajuste o import dependendo de onde você decidiu fixar o EventosBase.py)

class Bloco:
    """
    O Nó da nossa lista encadeada reversa. 
    Uma vez instanciado, seus atributos jamais devem ser alterados.
    """
    def __init__(self, evento: EventoLogistico, bloco_anterior: Optional['Bloco']):
        # 1. Payload Logístico (O Domínio)
        self.conteudo = evento
        
        # 2. Ponteiro Reversivo (A Infraestrutura)
        self.bloco_anterior = bloco_anterior
        
        # 3. Atributos Criptográficos
        self.hash_anterior = bloco_anterior.hash_atual if bloco_anterior else "0" * 64
        self.timestamp_bloco = datetime.now().isoformat()
        
        # O Hash atual é a última coisa a ser gerada, lacrando o bloco
        self.hash_atual = self._calcular_hash()

    def _calcular_hash(self) -> str:
        """
        Gera a assinatura digital (SHA-256) do bloco com base nos dados vitais.
        """
        # Criamos um dicionário estrito para não incluir ponteiros de memória no hash
        dados_para_hash = {
            "id_evento": str(self.conteudo.id_evento),
            "hash_anterior": self.hash_anterior,
            "timestamp": self.timestamp_bloco
        }
        
        # json.dumps com sort_keys garante que a ordem das chaves não mude o hash
        bloco_string = json.dumps(dados_para_hash, sort_keys=True)
        return hashlib.sha256(bloco_string.encode()).hexdigest()


class Blockchain:
    """
    O Descritor da estrutura. Gerencia exclusivamente o estado atual (a ponta) da corrente.
    """
    def __init__(self):
        # A blockchain só conhece o bloco mais recente. O resto é descoberto navegando para trás.
        self.ultimo: Optional[Bloco] = None
        self.tamanho: int = 0

    def adicionar_bloco(self, evento: EventoLogistico) -> None:
        """
        Acopla um novo evento à corrente se, e somente se, ele passar na auditoria do domínio.
        """
        # A responsabilidade da validação é polimórfica (cada evento sabe se validar)
        if not evento.validar_regras():
            raise ValueError(f"Bloco Rejeitado: O evento {evento.id_evento} possui inconformidades logísticas ou ambientais.")

        # Instancia o novo bloco apontando para o último bloco conhecido
        novo_bloco = Bloco(evento, self.ultimo)
        
        # Atualiza o descritor para apontar para a nova ponta
        self.ultimo = novo_bloco
        self.tamanho += 1

    def percorrer_historico(self) -> List[Dict]:
        """
        Varre a blockchain de trás para frente e inverte o resultado para exibição cronológica (Dashboard).
        """
        historico_reverso = []
        bloco_atual = self.ultimo
        
        # Navegação via ponteiro anterior O(n)
        while bloco_atual is not None:
            historico_reverso.append({
                "hash_bloco": bloco_atual.hash_atual,
                "hash_anterior": bloco_atual.hash_anterior,
                "evento_tipo": bloco_atual.conteudo.__class__.__name__,
                "id_evento": str(bloco_atual.conteudo.id_evento),
                "timestamp": bloco_atual.timestamp_bloco,
                "selo_procedencia": bloco_atual.conteudo.selo_procedencia
            })
            bloco_atual = bloco_atual.bloco_anterior
            
        # Inverte a lista para retornar da Gênese até o momento atual
        return historico_reverso[::-1]

    def validar_integridade_cadeia(self) -> bool:
        """
        O coração do compliance: Recalcula todos os hashes do passado para o presente
        para garantir que nenhum objeto foi adulterado na memória RAM.
        """
        bloco_atual = self.ultimo
        
        while bloco_atual is not None:
            # 1. Verifica se o hash salvo bate com o cálculo matemático atual
            if bloco_atual.hash_atual != bloco_atual._calcular_hash():
                return False
            
            # 2. Verifica se a ligação com o passado foi corrompida
            if bloco_atual.bloco_anterior is not None:
                if bloco_atual.hash_anterior != bloco_atual.bloco_anterior.hash_atual:
                    return False
                    
            bloco_atual = bloco_atual.bloco_anterior
            
        return True