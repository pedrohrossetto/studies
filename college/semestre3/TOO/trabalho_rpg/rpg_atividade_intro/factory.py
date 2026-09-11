from missao import *

class FactoryMissao():
    @staticmethod
    def criar_missao(tipo_missao,nome,descricao,recompensa,**kwargs):
        tipo_missao = tipo_missao.strip().lower()
        match tipo_missao:
            case "combate":
                missao = MissaoCombate(nome,
                                       descricao,
                                       recompensa,
                                       kwargs.get('inimigos_a_derrotar',1),
                                       kwargs.get('inimigo',"Inimigo Desconecido"),
                                       kwargs.get('status', StatusMissao.PENDENTE))
            case "coleta":
                missao = MissaoColeta(nome,
                                      descricao,
                                      recompensa,
                                      kwargs.get('item_necessario',"Item Desconecido"),
                                      kwargs.get('quantidade_item',1),
                                      kwargs.get('status', StatusMissao.PENDENTE))
            case "exploração":
                missao = MissaoExploracao(nome,
                                          descricao,
                                          recompensa,
                                          kwargs.get('local',"Local Desconecido"),
                                          kwargs.get('distancia', 0.0),
                                          kwargs.get('duracao', 60),
                                          kwargs.get('status', StatusMissao.PENDENTE))
            case _: 
                raise ValueError("Tipo de missão inválida. Escolha entre 'combate', 'coleta' ou 'exploração'.")
        return missao
            