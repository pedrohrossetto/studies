from personagem import Personagem
from item import Item, TipoItem
import os


input("Pressione Enter para Iniciar O RPG TOO:\n")
os.system('cls')

p_Pedro = Personagem(nome="Pedro", nivel=1,xp=0)


arma_espada_ferro = Item(nome="Espada de Ferro", descricao="Uma espada simples feita de ferro, ideal para iniciantes.", valor_efeito=5, tipo=TipoItem.ARMA)
vestimenta_cota_malha = Item(nome="Cota de Malha", descricao="Uma armadura leve feita de anéis de metal entrelaçados, oferece proteção básica.", valor_efeito=0.2, tipo=TipoItem.VESTIMENTA)
utilitario_pocao_vida = Item(nome="Poção de Vida Pequena", descricao="Uma poção que restaura uma quantidade pequena de vida quando consumida.", valor_efeito=30, tipo=TipoItem.UTILITARIO)


p_Pedro.adicionar_itens_inventario([arma_espada_ferro, vestimenta_cota_malha, utilitario_pocao_vida])


# input("Pressione Enter para Continuar:\n")
# os.system('cls')

# p_Pedro.equipar_item(arma_espada_ferro)

# input("Pressione Enter para Continuar:\n")
# os.system('cls')

# p_Pedro.equipar_item(vestimenta_cota_malha)

# input("Pressione Enter para Continuar:\n")
# os.system('cls')

# p_Pedro.exibir_informacoes()


input("Pressione Enter para Continuar:\n")
os.system('cls')

p_Pedro.equipar_para_missao()