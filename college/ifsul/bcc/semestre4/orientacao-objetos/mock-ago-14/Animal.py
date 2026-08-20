from random import Random


class Animal:
    def __iniit__(self, age: int, gender: str):
        self.__age:int = age
        self.__gender:str = gender

    @property
    def age(self) -> int:
        return self.__age

    @property
    def gender(self) -> str:
        return self.__gender

    @age.setter
    def set_age(self, age:int):
        self.__age = age

    @gender.setter
    def set_gender(self, gender:str):
        self.__gender = gender


    def mate(self, partner: 'Animal') -> 'Animal':
        if self.__gender != partner.gender:
            return Animal(0,Random.choice(['male','female']))
        return None
