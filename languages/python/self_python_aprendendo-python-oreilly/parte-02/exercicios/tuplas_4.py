X = 'spam'
Y = 'eggs'
X,Y = Y,X 
# está reatribuindo x=y,  y=x?
# R: Sim. É criada uma tupla temporária com temp = ("eggs","spam") e então é reatribuido
X,Y
Y,X
X
Y