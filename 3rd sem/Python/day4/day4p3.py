class Point:
    def __init__(self, x, y):
        self.x = x
        self.y = y

    def __str__(self):
        return f"({self.x},{self.y})"

    def __add__(self, other):
        return Point(self.x + other.x, self.y + other.y)

    def __sub__(self, other):
        return Point(self.x - other.x, self.y - other.y)

    def __mul__(self, value):
        return Point(self.x * value, self.y * value)

    def __truediv__(self, value):
        return Point(self.x / value, self.y / value)

    def __floordiv__(self, value):
        return Point(self.x // value, self.y // value)

    def __pow__(self, value):
        return Point(self.x ** value, self.y ** value)

    def __lt__(self, other):
        return self.x < other.x and self.y < other.y

    def __eq__(self, other):
        return self.x == other.x and self.y == other.y

    def __gt__(self, other):
        return self.x > other.x and self.y > other.y

    def __le__(self, other):
        return self.x <= other.x and self.y <= other.y

# Example usage
p1 = Point(41, 50)
p2 = Point(2, 3)

print(f"The first object is: {p1}")
print(f"The second object is: {p2}")
print(f"The sum of {p1} and {p2} is {p1 + p2}")
print(f"The difference of {p1} and {p2} is {p1 - p2}")
print(f"The product of {p1} and 5 is {p1 * 5}")
print(f"The division of {p1} and 5 is {p1 / 5}")
print(f"The integer division of {p1} and 5 is {p1 // 5}")
print(f"The Power of 3 of {p2} is {p2 ** 3}")

print(f"{p1} = {p2} is {p1 == p2}")
print(f"{p1} >= {p2} is {p1 >= p2}")
print(f"{p1} <= {p2} is {p1 <= p2}")
print(f"{p1} > {p2} is {p1 > p2}")
print(f"{p1} < {p2} is {p1 < p2}")


# output
# The first object is: (41,50)
# The second object is: (2,3)
# The sum of (41,50) and (2,3) is (43,53)
# The difference of (41,50) and (2,3) is (39,47)
# The product of (41,50) and 5 is (205,250)
# The division of (41,50) and 5 is (8.2,10.0)
# The integer division of (41,50) and 5 is (8,10)
# The Power of 3 of (2,3) is (8,27)
# (41,50) = (2,3) is False
# (41,50) >= (2,3) is True
# (41,50) <= (2,3) is False
# (41,50) > (2,3) is True
# (41,50) < (2,3) is False