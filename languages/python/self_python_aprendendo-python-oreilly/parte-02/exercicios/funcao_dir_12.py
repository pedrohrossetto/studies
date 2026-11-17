## dir serve como um "help"

print(f"string: {dir("string")}\n")
lista = [0,1,2,3]

print(f"lista: {dir(lista)}\n")

dic = {"a":1}

print(f"dic: {dir(dic)}\n")

dic = {"a":1,"lista":lista}

print(f"dic: {dir(dic)}\n")


print(f"geral: {dir()}\n")


import math

print(f"math import: {dir(math)}\n") ## 
