# Write a R program to create a list of heterogeneous data, which include character, numeric and logical vectors. Print the lists.

# Create a list of heterogeneous data
my_list <- list(
  character_vector = c("apple", "banana", "cherry"),
  numeric_vector = c(1.5, 2.3, 3.7),
  logical_vector = c(TRUE, FALSE, TRUE)
)

# Print the list
print(my_list)

# output
# $character_vector
# [1] "apple"  "banana" "cherry"

# $numeric_vector
# [1] 1.5 2.3 3.7

# $logical_vector
# [1]  TRUE FALSE  TRUE