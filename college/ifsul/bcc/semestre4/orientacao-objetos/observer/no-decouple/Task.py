from __future__ import annotations

from typing import TYPE_CHECKING

if TYPE_CHECKING:
    from .User import User

class Task:
    def __init__(self, user: User, _type:str):
        self.user:User = user
        self._type:str = _type
    def complete(self) -> None:
        self.user.add_experience(1)
        self.user.wallet.increase_balance(5)
        for badge in self.user.badges:
            if self._type == badge._type:
             badge.add_points(2)
