auto <- read.csv("/Users/sabyasachiganguli/Desktop/code/college codes/3rd sem/R/lab assignment/pdf/auto-mpg.csv", header = TRUE)

boxplot(auto$mpg, xlab = "Miles per gallon", col = "lightgray")
boxplot(mpg ~ cylinders, data = auto)
