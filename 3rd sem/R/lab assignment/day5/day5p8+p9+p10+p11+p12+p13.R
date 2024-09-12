# Read the CSV file
data <- read.csv("/Users/sabyasachiganguli/Desktop/code/college codes/3rd sem/R/lab assignment/pdf/ClassificationSimpleLab.csv", header = TRUE)

# Display the entire file
print(data)

# Display input variables (assuming class variable is the last column)
input_variables <- data[, -ncol(data)]
print(input_variables)

# Display the class variable (assuming it is the last column)
class_variable <- data[, ncol(data)]
print(class_variable)

# For every variable, display the number of distinct values and their counts
for (variable in names(data)) {
  distinct_values <- table(data[[variable]])
  cat("Variable:", variable, "\n")
  print(distinct_values)
  cat("\n")
}

# For every variable, display the number of distinct values and corresponding counts of the class values
for (variable in names(input_variables)) {
  cat("Cross-tabulation of", variable, "with class variable:\n")
  crosstab <- table(data[[variable]], class_variable)
  print(crosstab)
  cat("\n")
}
