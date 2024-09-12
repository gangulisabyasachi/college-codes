# (a)Find out the factorial of a number using iterative method.
# (b)using recursion.

# (a)
def factorial_iterative(n):
    result = 1
    for i in range(1, n + 1):
        result *= i
    return result

# Example usage
n = 5
print("Factorial of", n, "using iterative method is", factorial_iterative(n))

# (b)
def factorial_recursive(n):
    if n == 0:
        return 1
    else:
        return n * factorial_recursive(n - 1)

# Example usage
n = 5
print("Factorial of", n, "using recursion is", factorial_recursive(n))
# output
# Factorial of 5 using iterative method is 120
# Factorial of 5 using recursion is 120  