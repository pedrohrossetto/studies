class Badge(object):
    def __init__(self, name, _type):
        self.points = 0
        self.name = name
        self._type = _type
        self.awarded = False
    def add_points(self, amount):
        self.points += amount
        if self.points > 3:
            self.awarded = True
    def complete_task(self, task):
        if task._type == self._type:
            self.add_points(2)
    def __str__(self):
        if self.awarded:
            award_string = "Earned"
        else:
            award_string = "Unearned"
        return "{}: {} [{}]".format(
            self.name,
            award_string,
            self.points
        )
