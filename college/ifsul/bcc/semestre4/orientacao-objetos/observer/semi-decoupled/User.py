from typing import override


class User(object):
    def __init__(self, wallet):
        self.wallet = wallet
        self.badges = []
        self.experience:int = 0
    def add_experience(self, amount):
        self.experience += amount
    def complete_task(self,task):
        self.add_experience(1)

    @override
    def __str__(self):
        return "Wallet\t{}\nExperience\t{}\n+ Badges +\n{}\n++++++++++++++++".format(
            self.wallet,
            self.experience,
            "\n".join([ str(x) for x in self.badges])
        )
