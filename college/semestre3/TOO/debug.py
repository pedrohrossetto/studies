class Pagamento:
    def processar():
        print("")

class CartaoCredito(Pagamento):
    def processar(self):
        print("pagamento cartao de Crédito")

class CartaoDebito(Pagamento):
    def processar(self):
        print("pagamento Cartao Debito")

class Pix(Pagamento):
    def processar(self):
        print("pagamento Pix")

class Dinheiro(Pagamento):
    def processar(self):
        print("pagamento Dinheiro")

pagamentos = [CartaoCredito(),CartaoDebito(),Pix(),Dinheiro()]

for p in pagamentos:
    p.processar()