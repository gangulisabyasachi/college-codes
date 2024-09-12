install.packages("ggplot2")
library(ggplot2)
auto <- read.csv("/Users/sabyasachiganguli/Desktop/code/college codes/3rd sem/R/lab assignment/pdf/auto-mpg.csv")
auto$cylinders <- factor(auto$cylinders,
    levels = c(3, 4, 5, 6, 8),
    labels = c("3cyl", "4cyl", "5cyl", "6cyl", "8cyl")
)

ggplot(auto, aes(x=weight, y=mpg)) + geom_line()
ggplot(auto, aes(x=weight, y=mpg)) + geom_line() + geom_point() 
ggplot(auto, aes(x=cylinders, y=horsepower)) + geom_col(fill="red") 
ggplot(auto, aes(x=mpg, y=horsepower)) + geom_col(fill="green") 
ggplot(auto, aes(x=cylinders, y=horsepower)) + geom_col() 
ggplot(auto, aes(x=factor(cylinders),y=horsepower)) + geom_col()
