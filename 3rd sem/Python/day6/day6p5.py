from functools import reduce

# Part (a): Filter numbers divisible by 3 and 5
def divisible_by_3_and_5(lst):
    return list(filter(lambda x: x % 3 == 0 and x % 5 == 0, lst))

# Part (b): Square of each number using map
def square_numbers(lst):
    return list(map(lambda x: x ** 2, lst))

# Part (c): Product of all numbers using reduce
def product_of_numbers(lst):
    return reduce(lambda x, y: x * y, lst)

# Testing Q5
L = list(range(21))
print("List is:", L)
print("The numbers divisible by both 3 and 5 are:", divisible_by_3_and_5(L))
print("Square Numbers in list:", square_numbers(L))

user_input = [12, 2, 3, 4, 5]
print("List is:", user_input)
print("Product of all numbers:", product_of_numbers(user_input))


# output
# List is: [0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20]
# The numbers divisible by both 3 and 5 are: [0, 15]
# Square Numbers in list: [0, 1, 4, 9, 16, 25, 36, 49, 64, 81, 100, 121, 144, 169, 196, 225, 256, 289, 324, 361, 400]
# List is: [12, 2, 3, 4, 5]
# Product of all numbers: 1440