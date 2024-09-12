# Find out the sum of the digits of a number provided as command line argument.

import sys

if len(sys.argv) != 2:
    print("Usage: python sum_of_digits.py <number>")
    sys.exit(1)

number = sys.argv[1]

if not number.isdigit():
    print("Please provide a valid non-negative integer.")
    sys.exit(1)

sum_digits = sum(int(digit) for digit in number)
print(f"The sum of the digits of {number} is {sum_digits}.")


# output
# python day3p4.py 12345
# The sum of the digits of 12345 is 15.