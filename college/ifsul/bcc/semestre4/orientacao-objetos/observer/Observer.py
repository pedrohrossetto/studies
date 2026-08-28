from __future__ import annotations

from abc import ABC, abstractmethod
from typing import override


class Observer(ABC):

    @abstractmethod
    def update(self, observed):
        pass

class ConcreteObserver(Observer):
    @override
    def update(self, observed:Observable):
        print(f"Observing: {observed}")

class Observable:
    def __init__  (self):
        self.observers = set()

    def register(self, observer):
        self.observers.add(observer)

    def unregister(self, observer):
        self.observers.discard(observer)

    def unregister_all(self):
        self.observers = set()

    def update_all(self):
        for observer in self.observers:
            observer.update(self)

def main():
    observed = Observable()
    observer1 = ConcreteObserver()
    observed.register(lambda x: observer1.update(x))
    observed.update_all()

if __name__ == "__main__":
    main()
