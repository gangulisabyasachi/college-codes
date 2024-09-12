# Parameters
n <- 1000  # Number of random values
min <- 1   # Minimum value
max <- 100 # Maximum value
N <- 5     # Nth highest value

# Generate random vector using Uniform distribution
random_vector <- runif(n, min, max)

# Sort the vector in decreasing order
sorted_vector <- sort(random_vector, decreasing = TRUE)

# Find the Nth highest value
Nth_highest_value <- sorted_vector[N]

# Display the result
cat(N, "th highest value in the vector is:", Nth_highest_value, "\n")
