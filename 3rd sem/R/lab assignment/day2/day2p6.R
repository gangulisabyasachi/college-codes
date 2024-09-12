# Write a R program to create three vectors a,b,c with 3 integers. Combine the three vectors to become a 3×3 matrix where each column represents a vector. Print the content of the matrix.

# Create three vectors a, b, and c
a <- c(1, 2, 3)
b <- c(4, 5, 6)
c <- c(7, 8, 9)

# Combine the vectors into a 3x3 matrix
matrix_data <- cbind(a, b, c)

# Print the content of the matrix
print(matrix_data)

# Output
#      a b c
# [1,] 1 4 7
# [2,] 2 5 8
# [3,] 3 6 9