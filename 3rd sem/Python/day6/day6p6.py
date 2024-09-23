def positive_only(func):
    def wrapper(a, b):
        a = max(a, 0)
        b = max(b, 0)
        return func(a, b)
    return wrapper

@positive_only
def add_numbers(a, b):
    return a + b

# Testing Q6
a, b = -50, 60
print("Without decorator Sum is:", a + b)
print("With decorator Sum is:", add_numbers(a, b))


# output
# Without decorator Sum is: 10
# With decorator Sum is: 60