'''
Write a Python Program to calculate arithmetic operations on two numbers. That is, create a calculator that will take two numbers (example 5 and 2) and input. It will calculate the results of the following arithmetic operations:
+, -, *, /, %, //, **
'''


# Get the two numbers from the user
num1 = float(input("Enter first number: "))
num2 = float(input("Enter second number: "))

# Calculate the results of the arithmetic operations
addition = num1 + num2
subtraction = num1 - num2
multiplication = num1 * num2
division = num1 / num2
modulus = num1 % num2
floor_division = num1 // num2
exponentiation = num1 ** num2

# Print the results
print("Addition:", addition)
print("Subtraction:", subtraction)
print("Multiplication:", multiplication)
print("Division:", division)
print("Modulus:", modulus)
print("Floor Division:", floor_division)
print("Exponentiation:", exponentiation)

'''
Output
Enter first number: 92
Enter second number: 5
Addition: 97.0       
Subtraction: 87.0    
Multiplication: 460.0
Division: 18.4
Modulus: 2.0
Floor Division: 18.0
Exponentiation: 6590815232.0
'''