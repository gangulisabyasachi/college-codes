# Find out the maximum and minimum number among n numbers. Use the concept of variable argument list.

def find_max_min(*args):
    if not args:
        return None, None
    max_num = min_num = args[0]
    for num in args[1:]:
        if num > max_num:
            max_num = num
        if num < min_num:
            min_num = num
    return max_num, min_num

# Example usage
numbers = [56, 98, 42, 23, 89, 12]
max_num, min_num = find_max_min(*numbers)
print("Maximum number is", max_num)
print("Minimum number is", min_num)

# output
# Maximum number is 98
# Minimum number is 12