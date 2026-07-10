# if teste1:
#   instrucoes
# elif teste2:
#   instrucoes
# else:
#   instrucoes

x = "teste"

if x == "teste":
    print("IF")
elif x == "teste": # Se o primeiro if é bem sucedido, o elif não é executado
    print("ELIF")
if x == "testezinho": # testa independente de qualquer outro resultado
    print("IF2")
elif x == "teste": # É associado com seu if imediatamente acima
    print("ELIF2")
else:
    print("ELSE")

## A partir do Python 3 a lógica de switch case foi implementada com o match/case

comando = "salvar"

match comando:
    case "salvar":
        print("Salvando os dados...")
    case "deletar":
        print("Excluindo o arquivo...")
    case "sair":
        print("Fechando o programa...")
    case _:
        # O sublinhado (_) funciona como o "default" (o else do switch)
        print("Comando desconhecido.")

dia = "Sábado"

match dia:
    case "Segunda" | "Terça" | "Quarta" | "Quinta" | "Sexta":
        print("Dia de semana. Vá trabalhar.")
    case "Sábado" | "Domingo":
        print("Final de semana! Descanse.")


acao = ["mover", "cima"]

match acao:
    case ["parar"]:
        print("Parando o personagem.")
    case ["mover", "cima" | "baixo" | "esquerda" | "direita"]:
        print(f"Movendo para a direção especificada.")
    case ["atacar", arma]:
        # Ele joga o segundo valor do array direto na variável 'arma' dinamicamente
        print(f"Atacando o inimigo com: {arma}")
    case _:
        print("Ação inválida.")