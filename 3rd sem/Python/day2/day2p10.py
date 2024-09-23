# Finding the roots of a quadratic equation
# Take the coefficients a, b, and c of a quadratic equation 𝑎𝑥2+𝑏𝑥+𝑐=0 from the user.
# Find the roots (could be real & equal, real & unequal, or complex conjugate). Display the roots to the user in a proper format. Make at least 3 attempts to input the values of a, b, and c such that all the above three cases arise.
# Sample input and Output
# Enter the coefficient of x^2:1
# Enter the coefficient of x:-2
# Enter the constant term:1
# Roots are real and equal
# Root 1 is 1.0
# Root2 is 1.0

# Enter the coefficient of x^2:1
# Enter the coefficient of x:7
# Enter the constant term:12
# Roots are real and distinct
# Root 1 is -3.0
# Root2 is -4.0

# Enter the coefficient of x^2:1
# Enter the coefficient of x:1
# Enter the constant term:1
# Roots are imaginary
# Root1 is -0.5 +i 0.8660254037844386
# Root2 is -0.5 -i 0.8660254037844386

import math

# Get the coefficients from the user
a = float(input("Enter the coefficient of x^2: "))
b = float(input("Enter the coefficient of x: "))
c = float(input("Enter the constant term: "))

# Calculate the discriminant
discriminant = b**2 - 4*a*c

# Check the nature of roots
if discriminant > 0:
    print("Roots are real and distinct")
    root1 = (-b + math.sqrt(discriminant)) / (2*a)
    root2 = (-b - math.sqrt(discriminant)) / (2*a)
    print("Root 1 is", root1)
    print("Root2 is", root2)
elif discriminant == 0:
    print("Roots are real and equal")
    root1 = root2 = -b / (2*a)
    print("Root 1 is", root1)
    print("Root2 is", root2)
else:
    print("Roots are imaginary")
    real_part = -b / (2*a)
    imag_part = math.sqrt(-discriminant) / (2*a)
    print("Root1 is", real_part, "+i", imag_part)
    print("Root2 is", real_part, "-i", imag_part)

# Output
# Enter the coefficient of x^2: 1
# Enter the coefficient of x: -2
# Enter the constant term: 1
# Roots are real and equal
# Root 1 is 1.0
# Root2 is 1.0
