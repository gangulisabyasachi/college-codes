auto <- read.csv("/Users/sabyasachiganguli/Desktop/code/college codes/3rd sem/R/lab assignment/pdf/auto-mpg.csv", header = TRUE)
pairs(~ mpg + displacement, data = auto)
pairs(~ mpg + displacement + horsepower, data = auto)
