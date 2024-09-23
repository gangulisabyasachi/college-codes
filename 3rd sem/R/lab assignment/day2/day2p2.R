# Create the following matrices
#     a) A matrix of dimension 5×5 which contains 5L (integer) everywhere.
#     b) A matrix of dimension 10×1 which contains -100 (numeric) everywhere.
#     c) Check that the class of your result matrix is c("matrix", "array") or not?
#     d) Use is.matrix(), is.double(), is.integer(), and is.numeric() to check the type of the data of the matrix.



mat1 = array(5L, dim=c(5,5))
mat2 = array(-100, dim = c(10,1))
print("5x5 matrix: \n")
print(mat1)
cat("\nType Checks for 5x5 Matrix:\n")
cat("is.matrix: ", is.matrix(mat1), "\n")
cat("is.double: ", is.double(mat1), "\n")
cat("is.integer: ", is.integer(mat1), "\n")
cat("is.numeric: ", is.numeric(mat1), "\n")
cat("10x1 Matrix: \n")
print(mat2)
cat("\nType Checks for 5x5 Matrix:\n")
cat("is.matrix: ", is.matrix(mat2), "\n")
cat("is.double: ", is.double(mat2), "\n")
cat("is.integer: ", is.integer(mat2), "\n")
cat("is.numeric: ", is.numeric(mat2), "\n")

# Output
# [1] "5x5 matrix: \n"
#      [,1] [,2] [,3] [,4] [,5]
# [1,]    5    5    5    5    5
# [2,]    5    5    5    5    5
# [3,]    5    5    5    5    5
# [4,]    5    5    5    5    5
# [5,]    5    5    5    5    5

# Type Checks for 5x5 Matrix:
# is.matrix:  TRUE
# is.double:  FALSE
# is.integer:  TRUE 
# is.numeric:  TRUE
# 10x1 Matrix:
#       [,1]
#  [1,] -100
#  [2,] -100
#  [3,] -100
#  [4,] -100
#  [5,] -100
#  [6,] -100
#  [5,] -100
#  [6,] -100
#  [7,] -100
#  [8,] -100
#  [9,] -100
# [10,] -100

# Type Checks for 5x5 Matrix:
# is.matrix:  TRUE
# is.double:  TRUE
# is.integer:  FALSE
# is.numeric:  TRUE