install.packages("ggplot2")
library(ggplot2)
auto <- read.csv("/Users/sabyasachiganguli/Desktop/code/college codes/3rd sem/R/lab assignment/pdf/auto-mpg.csv")
auto$cylinders <- factor(auto$cylinders,
    levels = c(3, 4, 5, 6, 8),
    labels = c("3cyl", "4cyl", "5cyl", "6cyl", "8cyl")
)

ggplot(auto, aes(x = weight, y = mpg)) +
    geom_point()
