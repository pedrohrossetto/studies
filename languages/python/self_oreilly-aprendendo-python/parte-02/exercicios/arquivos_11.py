from pathlib import Path

# 1. Monta o caminho usando a barra normal do Linux
caminho = Path("aprendendo_python_oreilyy") / "parte2" / "exercicios" / "myfile.txt"

# 2. ESSA LINHA É O QUE ESTAVA FALTANDO: 
# Pega o pai do arquivo (as pastas) e cria todas de uma vez se não existirem
caminho.parent.mkdir(parents=True, exist_ok=True)

# 3. Agora que as pastas existem de verdade, você pode abrir e gravar
with open(caminho, "w", encoding="utf-8") as arquivo:
    print("Hello World!", file=arquivo)

# 4. Lê e valida
with open(caminho, "r", encoding="utf-8") as arquivo:
    print(arquivo.read())