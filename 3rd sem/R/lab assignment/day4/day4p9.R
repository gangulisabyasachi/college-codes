auto <- read.csv("/Users/sabyasachiganguli/Desktop/code/college codes/3rd sem/R/lab assignment/pdf/auto-mpg.csv", header = TRUE)

cyl <- table(auto$cylinders)
print(cyl)
barplot(cyl, main = "Barplot of cylinders", xlab = "cylinders", ylab = "frequency")


# output
# > source("/Users/sabyasachiganguli/Desktop/code/college codes/3rd sem/R/lab assignment/day4/day4p9.R", encoding = "UTF-8")

#   3   4   5   6   8
#   4 204   3  84 103