# 1. Installation and Loading Packages
# Install packages (only once)
# install.packages("packagename")

# Load packages (every session)
# library(packagename)

# 2. Basic Data Types and Type Conversion
x <- 1L       # integer
y <- 2        # numeric

# Type conversion
a <- as.numeric(x)  # convert integer to numeric
b <- as.integer(y)  # convert numeric to integer

# Print values
print(x)
print(y)
print(a)
print(b)

# Print classes
print(class(a))
print(class(b))

# 3. Assignment Operators
x <- 3          # Standard assignment
x = 3           # Alternative assignment
x <<- 3         # Super-assignment (usually used in functions)
3 -> x          # Rightward assignment
3 ->> x         # Rightward super-assignment

# 4. Case Sensitivity
x <- 1
y <- 3
z <- 4

# Correct
result1 <- x * y * z
print(result1)

# Error due to case sensitivity
# Uncomment the next line to see the error
# result2 <- x * Y * z

# 5. Basic Arithmetic
result1 <- 8 + 9 / 5^2
print(result1)

result2 <- 8 + 9 / (5 ^ 2)
print(result2)

result3 <- 8 + (9 / 5) ^ 2
print(result3)

result4 <- (8 + 9) / 5 ^ 2
print(result4)

# Integer division and modulo
int_div <- 42 %/% 4
mod <- 42 %% 4
print(int_div)
print(mod)

# 6. Control Statements
x <- 5
if (x > 10) {
  print(paste(x, "is greater than 10"))
} else {
  print(paste(x, "is less than 10"))
}

# 7. Functions
# Function to convert Fahrenheit to Celsius
fahrenheit_to_celsius <- function(temp_F) {
  temp_C <- (temp_F - 32) * 5 / 9
  return(temp_C)
}

# Call the function
print(fahrenheit_to_celsius(32))

# Function to check if a number is positive, negative, or zero
func <- function(x) {
  if (x > 0) {
    return("Positive")
  } else if (x < 0) {
    return("Negative")
  } else {
    return("Zero")
  }
}

# Call the function
print(func(1))
print(func(0))
print(func(-1))

# 8. For Loop
# For loop to print squares of numbers
for (i in 1:4) {
  print(i ^ 2)
}

# For loop with specific values
for (i in c(-8, 9, 11, 45)) {
  print(i)
}

# 9. Break and Next Statements
# Using break in a for loop
for (i in c(3, 6, 23, 19, 0, 21)) {
  if (i == 0) {
    break
  }
  print(i)
}
print("Outside Loop")

# Using next in a for loop
for (i in c(3, 6, 23, 19, 0, 21)) {
  if (i == 0) {
    next
  }
  print(i)
}
print('Outside Loop')

# 10. While Loop
i <- 1
while (i < 6) {
  print(i)
  i <- i + 1
}

# 11. Taking User Input
var <- readline("Enter the number: ")
var <- as.numeric(readline("Enter the number: "))
print(var)


# output

# # 1. Installation and Loading Packages
# # Install packages (only once)
# # install.packages("packagename")

# # Load packages (every session)
# # library(packagename)

# # 2. Basic Data Types and Type Conversion
# x <- 1L       # integer
# > # 1. Installation and Loading Packages
# > # Install packages (only once)
# > # install.packages("packagename")
# > 
# > # Load packages (every session)
# > # library(packagename)
# > 
# > # 2. Basic Data Types and Type Conversion
# > x <- 1L       # integer
# > y <- 2        # numeric
# > # Type conversion
# > a <- as.numeric(x)  # convert integer to numeric
# > b <- as.integer(y)  # convert numeric to integer
# > # Print values
# > print(x)
# [1] 1
# > print(y)
# [1] 2
# > print(a)
# [1] 1
# > print(b)
# [1] 2
# > # Print classes
# > print(class(a))
# [1] "numeric"
# > print(class(b))
# [1] "integer"
# > # 3. Assignment Operators
# > x <- 3          # Standard assignment
# > x = 3           # Alternative assignment
# > x <<- 3         # Super-assignment (usually used in functions)
# > 3 -> x          # Rightward assignment
# > 3 ->> x         # Rightward super-assignment
# > # 4. Case Sensitivity
# > x <- 1
# > y <- 3
# > z <- 4
# > # Correct
# > result1 <- x * y * z
# > print(result1)
# [1] 12
# > # Error due to case sensitivity
# > # Uncomment the next line to see the error
# # result2 <- x * Y * z
# > # result2 <- x * Y * z
# > 
# > # 5. Basic Arithmetic
# > result1 <- 8 + 9 / 5^2
# > print(result1)
# [1] 8.36
# > result2 <- 8 + 9 / (5 ^ 2)
# > print(result2)
# [1] 8.36
# > result3 <- 8 + (9 / 5) ^ 2
# > print(result3)
# [1] 11.24
# > result4 <- (8 + 9) / 5 ^ 2
# > print(result4)
# [1] 0.68
# > # Integer division and modulo
# > int_div <- 42 %/% 4
# > mod <- 42 %% 4
# > print(int_div)
# [1] 10
# > print(mod)
# [1] 2
# > # 6. Control Statements
# > x <- 5
# > if (x > 10) {
# +   print(paste(x, "is greater than 10"))
# + } else {
# +   print(paste(x, "is less than 10"))
# + }
# [1] "5 is less than 10"
# > # 7. Functions
# > # Function to convert Fahrenheit to Celsius
# > fahrenheit_to_celsius <- function(temp_F) {
# +   temp_C <- (temp_F - 32) * 5 / 9
# +   return(temp_C)
# + }
# > # Call the function
# > print(fahrenheit_to_celsius(32))
# [1] 0
# > # Function to check if a number is positive, negative, or zero
# > func <- function(x) {
# +   if (x > 0) {
# +     return("Positive")
# +   } else if (x < 0) {
# +     return("Negative")
# +   } else {
# +     return("Zero")
# +   }
# + }
# > # Call the function
# > print(func(1))
# [1] "Positive"
# > print(func(0))
# [1] "Zero"
# > print(func(-1))
# [1] "Negative"
# > # 8. For Loop
# > # For loop to print squares of numbers
# > for (i in 1:4) {
# +   print(i ^ 2)
# + }
# [1] 1
# [1] 4
# [1] 9
# [1] 16
# > # For loop with specific values
# > for (i in c(-8, 9, 11, 45)) {
# +   print(i)
# + }
# [1] -8
# [1] 9
# [1] 11
# [1] 45
# > # 9. Break and Next Statements
# > # Using break in a for loop
# > for (i in c(3, 6, 23, 19, 0, 21)) {
# +   if (i == 0) {
# +     break
# +   }
# +   print(i)
# + }
# [1] 3
# [1] 6
# [1] 23
# [1] 19
# > print("Outside Loop")
# [1] "Outside Loop"
# > # Using next in a for loop
# > for (i in c(3, 6, 23, 19, 0, 21)) {
# +   if (i == 0) {
# +     next
# +   }
# +   print(i)
# + }
# [1] 3
# [1] 6
# [1] 23
# [1] 19
# [1] 21
# > print('Outside Loop')
# [1] "Outside Loop"
# > # 10. While Loop
# > i <- 1
# > while (i < 6) {
# +   print(i)
# +   i <- i + 1
# + }
# [1] 1
# [1] 2
# [1] 3
# [1] 4
# [1] 5
# > # 11. Taking User Input
# > var <- readline("Enter the number: ")
# Enter the number: var <- as.numeric(readline("Enter the number: "))
# > print(var)
# [1] "var <- as.numeric(readline(\"Enter the number: \"))"
# > 
# > 