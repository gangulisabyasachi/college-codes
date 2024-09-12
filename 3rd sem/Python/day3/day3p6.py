# By using the concept of default arguments accept sides of a triangle( for three sides take default values ) and check the type of triangle and find out area of the triangle.

import math
def triangle_type_and_area(a=3, b=4, c=5):
    # Check the type of triangle
    if a == b == c:
        triangle_type = "Equilateral"
    elif a == b or b == c or a == c:
        triangle_type = "Isosceles"
    else:
        triangle_type = "Scalene"

    # Calculate the area using Heron's formula
    s = (a + b + c) / 2
    area = math.sqrt(s * (s - a) * (s - b) * (s - c))

    return triangle_type, area

# Example usage
a, b, c = 2,2,2
triangle_type, area = triangle_type_and_area(a, b, c)
print(f"Triangle with sides {a}, {b}, {c} is {triangle_type} and its area is {area:.2f}")

# Using default values
triangle_type, area = triangle_type_and_area()
print(f"Triangle with default sides is {triangle_type} and its area is {area:.2f}")

# output
# Triangle with sides 2, 2, 2 is Equilateral and its area is 1.73
# Triangle with default sides is Scalene and its area is 6.00
