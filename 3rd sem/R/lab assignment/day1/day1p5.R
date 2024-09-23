# Write a R program to print the first 10 Fibonacci numbers(recursion)

fibb <- function(x1, x2, i) {
    if (i == 10) {
        return()
    }
    print(x2)
    fibb(x2, x1 + x2, i + 1)
}

fibb(0, 1, 0)

# Output
# [1] 1
# [1] 1
# [1] 2
# [1] 3
# [1] 5
# [1] 8
# [1] 13
# [1] 21
# [1] 34
# [1] 55
