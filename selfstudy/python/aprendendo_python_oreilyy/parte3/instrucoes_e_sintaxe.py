a,b,c = 1,2,3
hex(id(a));hex(id(b));hex(id(c))
assert a is a # se retornar true, o programa segue se não interrompe tudo com AssertionError
a,b,c = range(3,10,3)
assert a is a # se retornar true, o programa segue se não interrompe tudo com AssertionError
a;b;c


def progress_bar():
    import sys #import local
    import time
    for i in range(1, 101):
        # O \r joga o cursor de volta para o início da mesma linha
        sys.stdout.write(f"\rProgresso: {i}%")
        sys.stdout.flush() # Força o terminal a renderizar o texto ime  diatamente
        time.sleep(0.05)

progress_bar()


codigo_em_string = """
for i in range(3):
    print(f"Linha {i}")
resultado = eval("2 + 2") ## eval converte apenas um elemento
"""

exec(codigo_em_string)
print(resultado)  # x passa a existir por que o exec transforma a string em código