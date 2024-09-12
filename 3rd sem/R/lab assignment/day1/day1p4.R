# Write a R program to print the first 10 Fibonacci numbers

n1 <- 0
n2 <- 1
i <- 0
print(n1)
while (i < 9) {
    print(n2)
    temp <- n1 + n2
    n1 <- n2
    n2 <- temp
    i <- i + 1
}


# Output
# [1] 0
# [1] 1
# [1] 1
# [1] 2
# [1] 3
# [1] 5
# [1] 8
# [1] 13
# [1] 21
# [1] 34
