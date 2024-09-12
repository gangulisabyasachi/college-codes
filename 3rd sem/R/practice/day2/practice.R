# R Functions

# Define a function to calculate the area of a circle
areaOfCircle <- function(radius) {
  area <- pi * radius^2
  return(area)
}

# Example usage
print(areaOfCircle(2))


# Built-in Functions

# Find sum, maximum, and minimum of numbers from 4 to 6
print(sum(4:6))
print(max(4:6))
print(min(4:6))


# Dots Arguments (Ellipsis)

# Function with ellipsis arguments
fun <- function(n, ...) {
  l <- list(n, ...)
  paste(l, collapse = " ")
}

# Example usage
print(fun(5, 1L, 6i, TRUE, "GeeksForGeeks", "Dots operator"))


# Vectors

# Create vectors
a <- c(1, 7, 32, 16)
b <- 1:10
c <- 20:15
d <- seq(1, 5, by = 0.5)
e <- seq(0, 10, length = 5)
f <- rep(0, 5)
g <- rep(1:3, 4)
h <- rep(4:6, 1:3)

# Print vectors
print(a)
print(b)
print(c)
print(d)
print(e)
print(f)
print(g)
print(h)


# Sorting Vectors

# Vector to be sorted
X <- c(8, 2, 7, 1, 11, 2)

# Sort in ascending order
A <- sort(X)
cat('Ascending order:', A, '\n')

# Sort in descending order
B <- sort(X, decreasing = TRUE)
cat('Descending order:', B, '\n')


# Lists

# Create a list with employee details
empId <- c(1, 2, 3, 4)
empName <- c("Debi", "Sandeep", "Subham", "Shiba")
numberOfEmp <- 4
empList <- list("ID" = empId, "Names" = empName, "Total Staff" = numberOfEmp)

# Print the list
print(empList)

# Access components by names
cat("Accessing name components using $ command\n")
print(empList$Names)


# Arrays

# Create a 3D array
arr <- array(2:13, dim = c(2, 3, 2))
print(arr)

# Naming arrays
row_names <- c("row1", "row2")
col_names <- c("col1", "col2", "col3")
mat_names <- c("Mat1", "Mat2")

# Create a named array
arr_named <- array(2:14, dim = c(2, 3, 2), dimnames = list(row_names, col_names, mat_names))
print(arr_named)


# R Packages

# Install the 'swirl' package
install.packages("swirl")

# Load the 'swirl' package
library(swirl)

# Start swirl for interactive learning
swirl()

# output

# # R Functions

# # Define a function to calculate the area of a circle
# areaOfCircle <- function(radius) {
#   area <- pi * radius^2
#   return(area)
# }
# > # R Functions
# > 
# > # Define a function to calculate the area of a circle
# > areaOfCircle <- function(radius) {
# +   area <- pi * radius^2
# +   return(area)
# + }
# > # Example usage
# > print(areaOfCircle(2))
# [1] 12.56637
# > # Built-in Functions
# > 
# > # Find sum, maximum, and minimum of numbers from 4 to 6
# > print(max(4:6))
# [1] 6
# > print(sum(4:6))
# [1] 15
# > print(min(4:6))
# [1] 4
# > # Dots Arguments (Ellipsis)
# > 
# > # Function with ellipsis arguments
# > fun <- function(n, ...) {
# + # Example usage
# +   l <- list(n, ...)
# + print(fun(5, 1L, 6i, TRUE, "GeeksForGeeks", "Dots operator"))
# +   paste(l, collapse = " ")
# + }
# > # Vectors
# > 
# > # Create vectors
# > a <- c(1, 7, 32, 16)
# > b <- 1:10
# > c <- 20:15
# > d <- seq(1, 5, by = 0.5)
# > e <- seq(0, 10, length = 5)
# > f <- rep(0, 5)
# > g <- rep(1:3, 4)
# > h <- rep(4:6, 1:3)
# > # Print vectors
# > print(a)
# [1]  1  7 32 16
# > print(b)
#  [1]  1  2  3  4  5  6  7  8  9 10
# > print(c)
# [1] 20 19 18 17 16 15
# > print(d)
# [1] 1.0 1.5 2.0 2.5 3.0 3.5 4.0 4.5 5.0
# > print(e)
# [1]  0.0  2.5  5.0  7.5 10.0
# > print(f)
# [1] 0 0 0 0 0
# > print(g)
#  [1] 1 2 3 1 2 3 1 2 3 1 2 3
# > print(h)
# [1] 4 5 5 6 6 6
# > # Sorting Vectors
# > 
# > # Vector to be sorted
# > X <- c(8, 2, 7, 1, 11, 2)
# > # Sort in ascending order
# > A <- sort(X)
# > cat('Ascending order:', A, '\n')
# Ascending order: 1 2 2 7 8 11 
# > # Sort in descending order
# > B <- sort(X, decreasing = TRUE)
# > cat('Descending order:', B, '\n')
# Descending order: 11 8 7 2 2 1 
# > # Lists
# > 
# > # Create a list with employee details
# > empId <- c(1, 2, 3, 4)
# > empName <- c("Debi", "Sandeep", "Subham", "Shiba")
# > numberOfEmp <- 4
# > empList <- list("ID" = empId, "Names" = empName, "Total Staff" = numberOfEmp)
# > # Print the list
# > print(empList)
# $ID
# [1] 1 2 3 4

# $Names
# [1] "Debi"    "Sandeep" "Subham"  "Shiba"  

# $`Total Staff`
# [1] 4

# > # Access components by names
# > cat("Accessing name components using $ command\n")
# Accessing name components using $ command
# > print(empList$Names)
# [1] "Debi"    "Sandeep" "Subham"  "Shiba"  
# > # Arrays
# > 
# > # Create a 3D array
# > arr <- array(2:13, dim = c(2, 3, 2))
# > print(arr)
# , , 1

#      [,1] [,2] [,3]
# [1,]    2    4    6
# [2,]    3    5    7

# , , 2

#      [,1] [,2] [,3]
# [1,]    8   10   12
# [2,]    9   11   13

# > # Naming arrays
# > row_names <- c("row1", "row2")
# > col_names <- c("col1", "col2", "col3")
# > mat_names <- c("Mat1", "Mat2")
# > # Create a named array
# > arr_named <- array(2:14, dim = c(2, 3, 2), dimnames = list(row_names, col_names, mat_names))
# > print(arr_named)
# , , Mat1

#      col1 col2 col3
# row1    2    4    6
# row2    3    5    7

# , , Mat2

#      col1 col2 col3
# row1    8   10   12
# row2    9   11   13

# > 