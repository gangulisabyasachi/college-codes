install.packages("ggplot2")
library(ggplot2)

myfun <- function(xvar) {
    1 / (1 + exp(-xvar + 10))
}
myfun1 <- function(xvar) {
    (xvar^3 - 5 * xvar)
}

ggplot(data.frame(x = c(-4, 4)), aes(x = x)) +
    stat_function(fun = myfun1, geom = "line")

ggplot(data.frame(x = c(0, 20)), aes(x = x)) +
    stat_function(fun = myfun, geom = "line")

ggplot(data.frame(x = c(0, 20)), aes(x, colour = "orange")) +
    stat_function(fun = myfun, geom = "line")
