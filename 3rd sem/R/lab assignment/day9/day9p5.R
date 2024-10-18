# Convert all columns to numeric (if there are non-numeric columns)
numeric_data <- data.frame(lapply(data, function(x) {
  if (is.factor(x)) {
    as.numeric(as.factor(x))  # Convert factors to numeric
  } else if (is.character(x)) {
    as.numeric(as.factor(x))  # Convert characters to numeric
  } else {
    x  # Keep numeric columns as is
  }
}))

# Check the structure to confirm all columns are numeric
str(numeric_data)

# Initialize K-Means Algorithm
kmeans_manual <- function(data, k, tol = 1e-4) {
  # Step 1: Arbitrarily choose k objects as initial centroids
  set.seed(123)
  initial_centroids <- data[sample(1:nrow(data), k), ]
  
  repeat {
    # Step 2: Assign each object to the cluster of the nearest centroid
    clusters <- apply(data, 1, function(row) {
      distances <- apply(initial_centroids, 1, function(centroid) sum((row - centroid)^2))
      return(which.min(distances))
    })
    
    # Step 3: Recalculate the centroids
    new_centroids <- sapply(1:k, function(c) {
      colMeans(data[clusters == c, , drop = FALSE], na.rm = TRUE)
    })
    
    # Step 4: Check if centroids have changed (using a tolerance for floating-point comparison)
    if (all(abs(new_centroids - initial_centroids) < tol, na.rm = TRUE)) {
      break
    }
    
    initial_centroids <- new_centroids
  }
  
  return(list(clusters = clusters, centroids = initial_centroids))
}

# Apply the K-Means Algorithm on the data with k=3 (example)
kmeans_result <- kmeans_manual(numeric_data, 3)

# Check the result
print(kmeans_result)
