# Finding the distance between two points whose coordinates are given
# Take coordinates of two points (in two dimension) from the user giving prompt. Find out the distance between the given points using the standard formula. Display the distance to the user in appropriate format.
# Sample Input and Output:
# Enter x-coordinate1:0
# Enter y-coordinate1:0
# Enter x-coordinate2:3
# Enter y-coordinate2:4
# The distance is 5.0

import math
x1 = float(input("Enter x1: "))
y1 = float(input("Enter y1: "))
x2 = float(input("Enter x2: "))
y2 = float(input("Enter y2: "))
dist = math.sqrt((x2-x1)**2+(y2-y1)**2)
print(f"The distance is {dist}")

# Output
# Enter x1: 1
# Enter y1: 1
# Enter x2: 0
# Enter y2: 0
# The distance is 1.4142135623730951