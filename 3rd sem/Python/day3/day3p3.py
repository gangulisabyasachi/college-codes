# (a)Print Fibonacci series upto n numbers.
# (b)using recursion.

# (a)
def fibonacci_iterative(n):
    fib_series = [0, 1]
    while len(fib_series) < n:
        fib_series.append(fib_series[-1] + fib_series[-2])
    return fib_series[:n]

# Example usage
n = 5
print("Fibonacci series up to", n, "numbers using iterative method is", fibonacci_iterative(n))

# (b)
def fibonacci_recursive(n):
    if n <= 0:
        return []
    elif n == 1:
        return [0]
    elif n == 2:
        return [0, 1]
    else:
        fib_series = fibonacci_recursive(n - 1)
        fib_series.append(fib_series[-1] + fib_series[-2])
        return fib_series

# Example usage
n = 5
print("Fibonacci series up to", n, "numbers using recursion is", fibonacci_recursive(n))

# output
# Fibonacci series up to 5 numbers using iterative method is [0, 1, 1, 2, 3]
# Fibonacci series up to 5 numbers using recursion is [0, 1, 1, 2, 3]   