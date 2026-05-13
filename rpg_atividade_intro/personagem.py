from typing import Optional
from item import Item, TipoItem
from missao import *
import os

class Personagem:
    def __init__(self, nome, nivel, xp):
        self._nome = nome
        self._nivel = nivel
        self._vida_base = 10 * nivel    
        self._ataque_base = 10 * nivel
        self._vida_vigente = self._vida_base
        self._ataque_vigente = self._ataque_base
        self._protecao_fisica = 0
        self._protecao_magica = 0
        self._xp = xp
        self.__missoes = []
        self.__inventario = []
        self.__equipamentos: dict[TipoItem, Item | None] = {tipo: None for tipo in TipoItem}
    @property
    def nome(self):
        return self._nome

    @nome.setter
    def nome(self, valor):
        if isinstance(valor, str) and valor.strip():
            self._nome = valor
        else:
            raise ValueError("Nome deve ser uma string não vazia")

    @property
    def vida_base(self):
        return self._vida_base
    
    @property
    def ataque_base(self):
        return self._ataque_base

    @property
    def vida(self):
        return self._vida_vigente

    @property
    def ataque(self):
        return self._ataque_vigente

    @property
    def nivel(self):
        return self._nivel

    @property
    def xp(self):
        return self._xp
    
    @property
    def missoes(self):
        return self.__missoes
    
    @property
    def inventario(self):
        return self.__inventario
    
    @property
    def equipamentos(self): 
        return self.__equipamentos

    def exibir_informacoes(self):
        print(f"Nome: {self.nome}")
        print(f"Vida Base: {self.vida_base}")
        print(f"Ataque Base: {self.ataque_base}")
        print(f"Vida Atual: {self.vida}")
        print(f"Ataque Atual: {self.ataque}")
        print(f"Nível: {self.nivel}")
        print(f"XP: {self.xp}")
        print(f"Missões Ativas: {[missao.nome for missao in self.missoes]}")
        print(f"Inventário: {[item.nome for item in self.inventario]}")
        print(f"Equipamentos: {[item.nome if item else 'Nenhum' for item in self.equipamentos.values()]}")


    def iniciar_missao_p(self,missao:Missao):
        if missao not in self.__missoes:
            try:
                self.__missoes.append(missao)
            except:
                 raise ValueError
            try:
                missao.iniciar_missao()
            except:
                raise ValueError      
            return
        else:
            print(f"Missão já iniciada para o personagem {self.nome}")
            return
        
    def progredir_missao(self, missao, progresso: int):
        # 1. Validação de segurança
        if missao not in self.__missoes:
            print(f"Missão não atribuída a {self.nome}")
            return

        # 2. Lógica de progresso (Polimórfica)
        # Todos os tipos de missão agora possuem a propriedade .objetivo
        alvo = missao.valor_objetivo 

        if progresso >= alvo:
            missao.concluir_missao()
            self._xp += missao.recompensa
            print(f"\n--- MISSÃO CONCLUÍDA ---")
            print(f"Missão: {missao.nome}")
            print(f"Recompensa: {missao.recompensa} XP")
            print(f"XP Total de {self.nome}: {self._xp}\n")
        else:
            print(f"Progresso em '{missao.nome}': {progresso}/{alvo}")

    def adicionar_item_inventario(self, item: Item):
        if item not in self.__inventario:
            try:
                self.__inventario.append(item)
                print(f"Item adicionado ao inventário de {self.nome}.")
                Item.exibir_informacoes(item)
            except ValueError:
                print(f"Erro ao adicionar o item '{item.nome}' ao inventário de {self.nome}.")
        else:
            print(f"Item '{item.nome}' já existe no inventário de {self.nome}.")
    def adicionar_itens_inventario(self, itens: list):
        for item in itens:
            self.adicionar_item_inventario(item)

    def remover_item_inventario(self, item: Item):
        if item in self.__inventario:
            try:
                self.__inventario.remove(item)
                print(f"Item '{item.nome}' removido do inventário de {self.nome}.")
            except ValueError:
                print(f"Erro ao remover o item '{item.nome}' do inventário de {self.nome}.")
        else:
            print(f"Item '{item.nome}' não encontrado no inventário de {self.nome}.")

    def remover_itens_inventario(self, itens: list):
        for item in itens:
            self.remover_item_inventario(item)
        
    def exibir_inventario(self):
        print(f"Inventário de {self._nome}")
        for item in self.inventario:
            indice = self.inventario.index(item)
            print(f" {indice}. {item.nome} - {str(item.tipo.value).title()}")
            
    def exibir_equipamentos(self):
        print(f"Equipamentos de {self._nome}")
        for slot, item in self.equipamentos.items():
            nome_item = item.nome if item is not None else 'Nenhum'
            print(f"{slot.tipo_item} - {nome_item}")

    def equipar_item(self, item: Item):
        if item not in self.__inventario:
            print(f"Item '{item.nome}' não encontrado no inventário.")
            return
        try:
            # 1. Descobrimos o slot (a chave do dicionário) através do tipo do item
            slot = item.tipo 
            # 2. Verificamos se já existe algo equipado nesse slot
            item_antigo = self.__equipamentos[slot]
            if item_antigo is not None:
                # Se existia algo, devolvemos para o inventário
                self.__inventario.append(item_antigo)
                print(f"Desequipando {item_antigo.nome}...")

            # 3. Agora removemos o novo item do inventário
            self.__inventario.remove(item)

            # 4. Colocamos o novo item no dicionário de equipamentos
            self.__equipamentos[slot] = item

            print(f"Item '{item.nome}' equipado no slot {str(slot.tipo_item).title()} por {self.nome}.")
            item.aplicar_ao_personagem(self)  # Aplicamos o efeito do item ao personagem
            item.exibir_informacoes() # Chamada direta se o método for de instância

        except ValueError:
            print(f"Erro ao manipular o inventário.")

        # Lógica de equipar o item (a ser implementada)
    def desequipar_slot(self, tipo_slot: TipoItem):
        item = self.__equipamentos[tipo_slot]
        try:
            if item:
                self.__equipamentos[tipo_slot] = None
                self.__inventario.append(item)

                print(f"{item.nome} movido para o inventário.")
        except ValueError:
            print(f"Erro ao desequipar o item do slot {tipo_slot.value}.")

    def equipar_itens(self, itens: list):
        for item in itens:
            self.equipar_item(item)
    def equipar_para_missao(self):
        mensagem = ""
        # Adicionado os parênteses no .lower()
        while mensagem.lower() != "iniciar":
            print("\n=== Preparação para a Missão ===")
            self.exibir_inventario()
            
            mensagem = input("\nDigite 'Iniciar' para partir, 'Status', 'Equipamentos' ou o NOME/NÚMERO do item: ").strip()

            # 1. Comandos de Verificação
            if mensagem.lower() == "status":
                self.exibir_informacoes()
                input("\nPressione Enter para Continuar:\n")
                os.system('cls')
                continue # Volta para o início do loop
            
            if mensagem.lower() == "equipamentos":
                self.exibir_equipamentos()
                input("\nPressione Enter para Continuar:\n")
                os.system('cls')
                continue

            if mensagem.lower() == "iniciar":
                break

            # 2. Lógica de Equipar por Índice (Número)
            if mensagem.isdecimal():
                indice = int(mensagem)
                if 0 <= indice < len(self.inventario):
                    self.equipar_item(self.inventario[indice])
                else:
                    print("Erro: Posição inválida no inventário.")
            
            # 3. Lógica de Equipar por Nome (Texto)
            else:
                # Uso do next com valor padrão None para evitar exceções
                item_escolhido = next((item for item in self.inventario if item.nome.lower() == mensagem.lower()), None)
                
                
                if item_escolhido:
                    self.equipar_item(item_escolhido)
                    input("\nPressione Enter para Continuar:\n")
                    os.system('cls')
                else:
                    print(f"Item '{mensagem}' não encontrado.")

        print("--- Preparação finalizada. Iniciando missão! ---")


    def __str__(self):
        return f"Personagem(nome='{self.nome}', vida={self.vida}, nível={self.nivel}, xp={self.xp})"

    def __eq__(self, outro):
        if not isinstance(outro, Personagem):
            return False
        return self.nome == outro.nome and self.vida == outro.vida and self.nivel == outro.nivel and self.xp == outro.xp

    