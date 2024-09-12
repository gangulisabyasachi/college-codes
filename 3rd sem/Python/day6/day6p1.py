import random

# Generate a list of size 20 with random numbers from 1 to 9
L = [random.randint(1, 9) for _ in range(20)]
print("Original List:", L)

# Part (a): Find unique elements
def unique(lst):
    result = []
    for item in lst:
        if lst.count(item) == 1:
            result.append(item)
    return result

# Part (b): Find duplicate elements
def duplicate(lst):
    result = {}
    for item in lst:
        count = lst.count(item)
        if count > 1 and item not in result:
            result[item] = count
    return result

# Part (c): Create a list of unique elements
def createuniq(lst):
    return list(set(lst))

# Testing Q1
print("Unique elements are:", unique(L))
print("Duplicate elements are:", duplicate(L))
print("List of Unique elements:", createuniq(L))


# output
# Original List: [9, 1, 5, 4, 7, 9, 1, 5, 5, 9, 7, 7, 1, 1, 1, 8, 2, 8, 5, 9]
# Unique elements are: [4, 2]
# Duplicate elements are: {9: 4, 1: 5, 5: 4, 7: 3, 8: 2}
# List of Unique elements: [1, 2, 4, 5, 7, 8, 9]