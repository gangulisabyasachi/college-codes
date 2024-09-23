df <- data.frame(
    col1 = 1:10,
    col2 = 11:20,
    col3 = c(30, 29, 28, 27, 26, 25, 24, 23, 22, 21),
    col4 = c(3, 5, 2, 1, 7, 6, 9, 2, 3, 4)
)

# Pairwise correlation between all variables
all_cor <- cor(df)

# Print the matrix
print(all_cor)
