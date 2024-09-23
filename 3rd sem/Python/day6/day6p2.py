# Helper function to find the second largest element
def find_second_largest(lst):
    unique_lst = list(set(lst))
    unique_lst.sort(reverse=True)
    return unique_lst[1] if len(unique_lst) > 1 else None

# Helper function to find the second smallest element
def find_second_smallest(lst):
    unique_lst = list(set(lst))
    unique_lst.sort()
    return unique_lst[1] if len(unique_lst) > 1 else None

# Main function to find the required sum
def sum_of_second_elements(lst):
    even_position_elements = lst[::2]
    odd_position_elements = lst[1::2]

    second_largest = find_second_largest(even_position_elements)
    second_smallest = find_second_smallest(odd_position_elements)

    return (second_largest or 0) + (second_smallest or 0)

# Testing Q2
L = [23, 2, 83, 9, 18, 20, 55, 65, 81, 79]
print("Even position elements:", L[::2])
print("Odd position elements:", L[1::2])
print("Required Sum is:", sum_of_second_elements(L))


# output
# Even position elements: [23, 83, 18, 55, 81]
# Odd position elements: [2, 9, 20, 65, 79]
# Required Sum is: 90