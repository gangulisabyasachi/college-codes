# Create the matrix
# ## [,1] [,2] [,3] [,4] [,5]
# ## [1,] -1 -1 -7 -1 -1
# ## [2,] 0 0 10 0 0
# ## [3,] 11 12 7 9 1
# Get the largest and smallest value in the matrix (minimum and maximum).

# Perform transpose operation on the matrix.

v <- c(-1, -1, -7, -1, -1, 0, 0, 10, 0, 0, 11, 12, 7, 9, 1)
mat=array(v, dim=c(3,5))
cat("Original Matrix:\n")
print(mat)
largest=max(v)
smallest=min(v)
transpose=t(mat)
cat("Largest value", largest, "\n")
cat("Smallest value", smallest, "\n")
cat("Transpose matrix: \n")
print(transpose)

# output
# Original Matrix:
#      [,1] [,2] [,3] [,4] [,5]
# [1,]   -1   -1    0    0    7
# [2,]   -1   -1   10   11    9
# [3,]   -7    0    0   12    1
# Largest value 12
# Smallest value -7
# Transpose matrix: 
#      [,1] [,2] [,3]
# [1,]   -1   -1   -7
# [2,]   -1   -1    0
# [3,]    0   10    0
# [4,]    0   11   12
# [5,]    7    9    1