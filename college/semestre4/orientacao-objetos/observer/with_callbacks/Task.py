from __future__ import annotations

from typing import TYPE_CHECKING

if TYPE_CHECKING:
    from .User import User


class Task:
    def __init__(self, user:User, _type):
        self.user = user
        self._type = _type
        self.callbacks = [
            self.user,
            self.user.wallet,
        ]
        self.callbacks.extend(self.user.badges)

    def complete(self):
        for item in self.callbacks:
            item.complete_task(self)
