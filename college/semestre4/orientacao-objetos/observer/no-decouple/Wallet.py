class Wallet(object):
    def __init__(self):
        self.amount = 0
    def increase_balance(self, amount):
        self.amount += amount
    def decrease_balance(self, amount):
        self.amount -= amount
    def __str__(self):
        return str(self.amount)
