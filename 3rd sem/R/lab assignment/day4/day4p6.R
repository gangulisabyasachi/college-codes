auto <- read.csv("/Users/sabyasachiganguli/Desktop/code/college codes/3rd sem/R/lab assignment/pdf/auto-mpg.csv", header = TRUE)
barplot(auto$mpg, main = "MPG Plot", xlab = "mpg", col = "black", horiz = FALSE)
