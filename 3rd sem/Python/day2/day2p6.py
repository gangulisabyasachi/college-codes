# Write a program to find the maximum, minimum and average of three numbers.

num1 = float(input("Enter the first number: "))
num2 = float(input("Enter the second number: "))
num3 = float(input("Enter the third number: "))

if num1 >= num2 and num1 >= num3:
    maximum = num1
elif num2 >= num1 and num2 >= num3:
    maximum = num2
else:
    maximum = num3

if num1 <= num2 and num1 <= num3:
    minimum = num1
elif num2 <= num1 and num2 <= num3:
    minimum = num2
else:
    minimum = num3

average = (num1 + num2 + num3) / 3

print("Maximum:", maximum)
print("Minimum:", minimum)
print("Average:", average)

# Output
# Enter the first number: 2
# Enter the second number: 22
# Enter the third number: 213
# Maximum: 213.0
# Minimum: 2.0
# Average: 79.0
