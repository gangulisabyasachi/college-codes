# Develop a simple calculator to accept two floating point numbers from the key-board. Then display a menu to the user and let him/her select a mathematical operation to be performed on those two numbers. Then display the answer. A sample run of your program should be similar to the following:
# Enter number 1:20
# Enter number 2: 12
# Mathematical Operations:
# 1-Add
# 2-Subtract
# 3-Multiply
# 4-Divide
# Enter your preference: 2
# Answer: 8.00


num1 <- as.numeric(readline("Enter num 1: "))
num2 <- as.numeric(readline("Enter num 2: "))

print("1. Addition")
print("2. Subtraction")
print("3. Multiply")
print("4. Divide")
print("5. Exponential")

pref <- as.integer(readline("Enter your preference: "))
if (pref == 1) {
    print(paste(num1 + num2))
} else if (pref == 2) {
    print(paste(num1 - num2))
} else if (pref == 3) {
    print(paste(num1 * num2))
} else if (pref == 4) {
    print(paste(num1 / num2))
} else if (pref == 5) {
    print(paste(num1^num2))
} else {
    print("Enter a valid choice")
}


# Output
# Enter num 1: 8
# Enter num 2: 5
# [1] "1. Addition"
# [1] "2. Subtraction"
# [1] "3. Multiply"
# [1] "4. Divide"
# [1] "5. Exponential"
# Enter your preference: 5
# [1] "32768"