# Install and load the necessary package
install.packages("dbscan")
library(dbscan)

# Read the data file
data <- read.csv("/Users/sabyasachiganguli/Desktop/code/college codes/3rd sem/R/lab assignment/pdf/UtilitiesLab.csv")

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

# Check if data is now fully numeric
str(numeric_data)

# Perform DBSCAN with eps=0.45 and MinPts=3
dbscan_cl <- dbscan(numeric_data, eps = 0.45, minPts = 3)

# Check the clusters
print(dbscan_cl)

# Plot the clusters
pairs(numeric_data, col = dbscan_cl$cluster + 1L, main = "DBSCAN Clusters")
