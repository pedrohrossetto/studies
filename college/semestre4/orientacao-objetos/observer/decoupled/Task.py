from __future__ import annotations

from typing import TYPE_CHECKING

if TYPE_CHECKING:
    from .User import User


class Task:
    def __init__(self, user:User, _type):
        self.observers = set()
        self.user = user
        self._type = _type

    def register(self,observer):
        self.observers.add(observer)

    def unregister(self,observer):
        self.observers.discard(observer)

    def unregister_all(self,observer):
        self.observers = set()


    def update_all(self):
        for observer in self.observers:
            observer.update(self)

    def complete(self):
        self.user.add_experience(1)
        self.user.wallet.increase_balance(5)
        for badge in self.user.badges:
            if self._type == badge._type:
             badge.add_points(2)
