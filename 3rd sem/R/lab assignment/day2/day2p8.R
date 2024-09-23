# Write a R program to create a two-dimensional 5x3 array of sequence of even integers greater than 50.

# Generate a sequence of even integers greater than 50
even_integers <- seq(52, by = 2, length = 15)

# Create a 5x3 array with the sequence
array_5x3 <- array(even_integers, dim = c(5, 3))

# Print the array
print("5x3 Array of even integers greater than 50:")
print(array_5x3)

# Output
# [1] "5x3 Array of even integers greater than 50:" 
#      [,1] [,2] [,3]
# [1,]   52   62   72
# [2,]   54   64   74
# [3,]   56   66   76
# [4,]   58   68   78
# [5,]   60   70   80