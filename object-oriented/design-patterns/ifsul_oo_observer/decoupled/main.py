from .badge import Badge
from .observer import  Observable
from .task import Task
from .user import User
from .wallet import Wallet


def main():
    wallet = Wallet()
    user = User(wallet)
    badges = [
        Badge("Fun Badge", 1),
        Badge("Bravery Badge", 2),
        Badge("Missing Badge", 3)
    ]
    user.badges.extend(badges)
    tasks = [Task(user, 1), Task(user, 1), Task(user, 3)]
    for task in tasks:
        task.register(wallet)
        task.register(user)
        for badge in badges:
            task.register(badge)
    for task in tasks:
        task.update_all()
    print(user)
if __name__ == "__main__":
    main()
