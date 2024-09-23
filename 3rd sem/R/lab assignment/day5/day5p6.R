# Load necessary library
install.packages("e1071")
library(e1071)

# Generate random normal distribution data
set.seed(123)  # For reproducibility
data <- rnorm(1000, mean = 0, sd = 1)

# Create a bell curve
hist(data, breaks = 30, probability = TRUE, 
     main = "Bell Curve of Random Normal Distribution", 
     xlab = "Value", ylab = "Density", col = "skyblue", border = "black")

# Add a normal distribution curve
curve(dnorm(x, mean = mean(data), sd = sd(data)), 
      col = "darkblue", lwd = 2, add = TRUE)

# Calculate skewness
skewness_value <- skewness(data)
cat("Skewness of the distribution:", skewness_value, "\n")
