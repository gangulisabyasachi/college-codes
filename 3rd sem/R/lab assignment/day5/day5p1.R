getmode <- function(v) {
    uniqv <- unique(v)
    uniqv[which.max(tabulate(match(v, uniqv)))]
}
x <- c(1, 2, 1, 3, 2, 4, 4, 4, 3, 2, 1, 5, 5, 4, 5)
result.mean <- mean(x)
print(result.mean)
result.median <- median(x)
print(result.median)
result.mode <- getmode(x)
print(result.mode)
