from .Badge import Badge
from .Task import Task
from .User import User
from .Wallet import Wallet


def main():
    wallet = Wallet()
    user = User(wallet)
    user.badges.append(Badge("Fun Badge", 1))
    user.badges.append(Badge("Bravery Badge", 2))
    user.badges.append(Badge("Missing Badge", 3))
    tasks = [Task(user, 1), Task(user, 1), Task(user, 3)]
    for task in tasks:
        task.complete()
    print(user)

if __name__ == "__main__":
    main()
