from .User import User


class Task(object):
    def __init__(self, user:User, _type):
        self.user = user
        self._type = _type
    def complete(self):
        self.user.add_experience(1)
        self.user.wallet.increase_balance(5)
        for badge in self.user.badges:
            if self._type == badge._type:
             badge.add_points(2)
