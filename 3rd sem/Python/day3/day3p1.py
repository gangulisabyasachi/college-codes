# (a)Write a program to find out gcd of two numbers using function.
# (b)using recursion.
# (c)Find out the gcd of n numbers.

# (a)
def gcd(a, b):
    while b != 0:
        a, b = b, a % b
    return a


# Example usage
a = 56
b = 98
print("GCD of", a, "and", b, "is", gcd(a, b))

# (b)


def gcd_recursive(a, b):
    if b == 0:
        return a
    else:
        return gcd_recursive(b, a % b)


# Example usage
a = 56
b = 98
print("GCD of", a, "and", b, "is", gcd_recursive(a, b))

# (c)


def gcd(a, b):
    while b != 0:
        a, b = b, a % b
    return a


def gcd_n(numbers):
    result = numbers[0]
    for num in numbers[1:]:
        result = gcd(result, num)
    return result


# Example usage
numbers = [56, 98, 42, 40, 100, 99]
print("GCD of", numbers, "is", gcd_n(numbers))

# output
# GCD of 56 and 98 is 14
# GCD of 56 and 98 is 14
# GCD of [56, 98, 42, 40, 100, 99] is 1