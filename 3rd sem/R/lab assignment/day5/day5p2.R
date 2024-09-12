# Creating the data frame
df <- data.frame(
    col1 = 1:10,
    col2 = 11:20,
    col3 = c(30, 29, 28, 27, 26, 25, 24, 23, 22, 21),
    col4 = c(3, 5, 2, 1, 7, 6, 9, 2, 3, 4)
)

# Displaying the data frame
print(df)


cor_col1_col2 <- cor(df$col1, df$col2)
cor_col1_col3 <- cor(df$col1, df$col3)
cor_col1_col4 <- cor(df$col1, df$col4)
cor_col3_col4 <- cor(df$col3, df$col4)

# Displaying the results
cat("Correlation between col1 and col2:", cor_col1_col2, "\n")
cat("Correlation between col1 and col3:", cor_col1_col3, "\n")
cat("Correlation between col1 and col4:", cor_col1_col4, "\n")
cat("Correlation between col3 and col4:", cor_col3_col4, "\n")

# Creating the data frame
df <- data.frame(
  col1 = 1:10,
  col2 = 11:20,
  col3 = c(30, 29, 28, 27, 26, 25, 24, 23, 22, 21),
  col4 = c(3, 5, 2, 1, 7, 6, 9, 2, 3, 4)
)

# Selecting the relevant columns
df_subset1 <- df[, c("col1", "col4", "col2")]

# Calculating the correlation matrix
cor_matrix1 <- cor(df_subset1)

# Displaying the correlation matrix
print(cor_matrix1)


# Selecting the relevant columns
df_subset2 <- df[, c("col2", "col3", "col4")]

# Calculating the correlation matrix
cor_matrix2 <- cor(df_subset2)

# Displaying the correlation matrix
print(cor_matrix2)


# Calculating the correlation matrix
cor_matrix <- cor(df)

# Displaying the correlation matrix
print(cor_matrix)
