df <- data.frame(
    col1 = 1:10,
    col2 = 11:20,
    col3 = c(30, 29, 28, 27, 26, 25, 24, 23, 22, 21),
    col4 = c(3, 5, 2, 1, 7, 6, 9, 2, 3, 4)
)

# Pairwise correlation between col1, col4 and col2
pairwise_cor1 <- cor(df[, c("col1", "col4", "col2")])

# Print the matrix
print(pairwise_cor1)

# Pairwise correlation between col2, col3, col4
pairwise_cor2 <- cor(df[, c("col2", "col3", "col4")])

# Print the matrix
print(pairwise_cor2)
