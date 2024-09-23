# Write R programs to find the maximum, minimum, sum, and mean value of a given vector without using the in-built functions.

# Function to find the maximum value
find_max <- function(vec) {
  max_val <- vec[1]
  for (i in vec) {
    if (i > max_val) {
      max_val <- i
    }
  }
  return(max_val)
}

# Function to find the minimum value
find_min <- function(vec) {
  min_val <- vec[1]
  for (i in vec) {
    if (i < min_val) {
      min_val <- i
    }
  }
  return(min_val)
}

# Function to find the sum
find_sum <- function(vec) {
  sum_val <- 0
  for (i in vec) {
    sum_val <- sum_val + i
  }
  return(sum_val)
}

# Function to find the mean
find_mean <- function(vec) {
  sum_val <- find_sum(vec)
  mean_val <- sum_val / length(vec)
  return(mean_val)
}

# Example usage
vec <- c(10, 20, 30, 40, 50)

cat("Maximum value:", find_max(vec), "\n")
cat("Minimum value:", find_min(vec), "\n")
cat("Sum:", find_sum(vec), "\n")
cat("Mean:", find_mean(vec), "\n")


# Output
# Maximum value: 50 
# Minimum value: 10 
# Sum: 150 
# Mean: 30