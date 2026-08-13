from missao import *
from personagem import *
from status import EstadoPendente  # Importamos a classe do estado explicitamente

# 1. Criação do personagem
p_Bianca = Personagem("Bianca Heroína", 100, 0)

# 2. Criação das missões
# Agora você passa a CLASSE EstadoPendente diretamente, sem os parênteses de instância!
missao_tutorial = MissaoCombate(
    "Complete o Tutorial", 
    "Complete o Tutorial", 
    50, 
    1, 
    "Dragão Celestial",
    EstadoPendente
)

# A outra pode continuar sem o argumento, pegando o valor padrão automaticamente
missao_coletar_ervas = MissaoColeta(
    "Colete Ervas", 
    "O Curandeiro da vila pediu para pegar ervas-raras", 
    20, 
    "Erva-Rara", 
    10
)

# 3. Execução
p_Bianca.iniciar_missao_p(missao_tutorial)
p_Bianca.iniciar_missao_p(missao_tutorial)
p_Bianca.progredir_missao(missao_tutorial)
p_Bianca.progredir_missao(missao_tutorial)
