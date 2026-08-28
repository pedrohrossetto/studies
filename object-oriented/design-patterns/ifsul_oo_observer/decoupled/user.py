from __future__ import annotations

from typing import TYPE_CHECKING, override

if TYPE_CHECKING:
    from .Badge import Badge
    from .Task import Task
    from .Wallet import Wallet


class User:
    def __init__(self, wallet:Wallet):
        self.wallet:Wallet = wallet
        self.badges: list[Badge] = []
        self.experience:int = 0
    def add_experience(self, amount:int)-> None:
        self.experience += amount

    def complete_task(self,task)-> None:
        self.add_experience(1)

    def update(self, observed):
        self.add_experience(1)

    @override
    def __str__(self):
        return "Wallet\t{}\nExperience\t{}\n+ Badges +\n{}\n++++++++++++++++".format(
            self.wallet,
            self.experience,
            "\n".join([ str(x) for x in self.badges])
        )
