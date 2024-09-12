# Write a python program to swap two numbers

a = int(input("Enter 1st number: "))
b = int(input("Enter 2nd number: "))
print(f"Before Swapping: a = {a} & b = {b}")
temp = a
a = b
b = temp
print(f"After Swapping: a = {a} & b = {b}")

'''
Output
Enter 1st number: 1
Enter 2nd number: 92
Before Swapping: a = 1 & b = 92
After Swapping: a = 92 & b = 1
'''
