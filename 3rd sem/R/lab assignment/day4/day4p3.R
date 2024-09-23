auto <- read.csv("/Users/sabyasachiganguli/Desktop/code/college codes/3rd sem/R/lab assignment/pdf/auto-mpg.csv", header = TRUE)
auto$cylinders <- factor(auto$cylinders, levels = c(3, 4, 5, 6, 8), labels = c("3cyl", "4cy]", "5cyl", "6cyl", "8cy]"))
auto$cylinders

# output

# >
# > auto <- read.csv("/Users/sabyasachiganguli/Desktop/code/college codes/3rd sem/R/lab assignment/pdf/auto-mpg.csv", header = TRUE)
# > auto$cylinders <- factor(auto$cylinders, levels = c(3, 4, 5, 6, 8), labels = c("3cyl", "4cy]", "5cyl", "6cyl", "8cy]"))
# > auto$cylinders
#   [1] 4cy] 3cyl 4cy] 4cy] 6cyl 4cy] 8cy] 4cy] 6cyl 8cy] 8cy] 6cyl 8cy] 4cy] 8cy]
#  [16] 4cy] 4cy] 8cy] 8cy] 4cy] 6cyl 4cy] 4cy] 4cy] 4cy] 8cy] 4cy] 8cy] 6cyl 4cy]
#  [31] 4cy] 8cy] 4cy] 4cy] 4cy] 8cy] 6cyl 4cy] 4cy] 4cy] 6cyl 8cy] 6cyl 8cy] 4cy]
#  [46] 4cy] 8cy] 6cyl 8cy] 6cyl 4cy] 6cyl 4cy] 8cy] 8cy] 4cy] 4cy] 4cy] 8cy] 8cy]
#  [61] 4cy] 4cy] 8cy] 8cy] 8cy] 4cy] 8cy] 8cy] 6cyl 8cy] 4cy] 6cyl 6cyl 4cy] 6cyl
#  [76] 8cy] 6cyl 4cy] 8cy] 8cy] 4cy] 4cy] 4cy] 4cy] 6cyl 8cy] 4cy] 8cy] 4cy] 4cy]
#  [91] 8cy] 8cy] 4cy] 4cy] 4cy] 4cy] 4cy] 8cy] 4cy] 8cy] 4cy] 4cy] 4cy] 8cy] 4cy]
# [106] 4cy] 4cy] 8cy] 4cy] 6cyl 4cy] 8cy] 8cy] 4cy] 6cyl 4cy] 6cyl 4cy] 4cy] 4cy]
# [121] 4cy] 8cy] 8cy] 6cyl 8cy] 8cy] 4cy] 4cy] 8cy] 4cy] 4cy] 4cy] 8cy] 8cy] 8cy]
# [136] 4cy] 6cyl 4cy] 8cy] 8cy] 8cy] 4cy] 8cy] 4cy] 8cy] 4cy] 6cyl 4cy] 6cyl 4cy]
# [151] 4cy] 8cy] 4cy] 4cy] 4cy] 4cy] 6cyl 8cy] 4cy] 4cy] 6cyl 4cy] 8cy] 8cy] 4cy]
# [166] 8cy] 8cy] 4cy] 4cy] 8cy] 5cyl 8cy] 4cy] 6cyl 8cy] 4cy] 6cyl 6cyl 4cy] 4cy]
# [181] 4cy] 6cyl 6cyl 6cyl 4cy] 8cy] 8cy] 4cy] 4cy] 8cy] 4cy] 4cy] 8cy] 4cy] 4cy]
# [196] 4cy] 4cy] 8cy] 3cyl 4cy] 6cyl 6cyl 6cyl 4cy] 4cy] 8cy] 6cyl 4cy] 6cyl 4cy]
# [211] 4cy] 4cy] 8cy] 4cy] 6cyl 4cy] 4cy] 4cy] 6cyl 4cy] 4cy] 8cy] 6cyl 8cy] 6cyl
# [226] 8cy] 4cy] 4cy] 4cy] 4cy] 4cy] 4cy] 8cy] 4cy] 8cy] 4cy] 4cy] 6cyl 6cyl 8cy]
# [241] 4cy] 4cy] 4cy] 4cy] 4cy] 4cy] 6cyl 8cy] 4cy] 4cy] 3cyl 8cy] 8cy] 8cy] 4cy]
# [256] 4cy] 4cy] 6cyl 4cy] 4cy] 4cy] 4cy] 4cy] 4cy] 4cy] 4cy] 8cy] 4cy] 4cy] 6cyl
# [271] 4cy] 4cy] 6cyl 6cyl 4cy] 6cyl 6cyl 4cy] 4cy] 4cy] 8cy] 6cyl 8cy] 6cyl 8cy]
# [286] 4cy] 6cyl 4cy] 4cy] 5cyl 8cy] 6cyl 4cy] 6cyl 4cy] 4cy] 4cy] 4cy] 4cy] 6cyl
# [301] 4cy] 4cy] 4cy] 4cy] 6cyl 8cy] 4cy] 6cyl 4cy] 6cyl 8cy] 6cyl 4cy] 4cy] 6cyl
# [316] 5cyl 4cy] 4cy] 4cy] 8cy] 8cy] 4cy] 4cy] 6cyl 6cyl 4cy] 4cy] 8cy] 4cy] 4cy]
# [331] 4cy] 4cy] 6cyl 6cyl 4cy] 6cyl 6cyl 4cy] 4cy] 8cy] 6cyl 4cy] 6cyl 8cy] 8cy]
# [346] 4cy] 8cy] 4cy] 4cy] 8cy] 8cy] 4cy] 6cyl 8cy] 4cy] 6cyl 8cy] 8cy] 4cy] 4cy]
# [361] 4cy] 8cy] 6cyl 6cyl 3cyl 6cyl 4cy] 8cy] 4cy] 6cyl 4cy] 4cy] 6cyl 6cyl 4cy]
# [376] 4cy] 6cyl 8cy] 4cy] 6cyl 6cyl 6cyl 4cy] 4cy] 6cyl 4cy] 8cy] 4cy] 8cy] 8cy]
# [391] 4cy] 4cy] 8cy] 6cyl 4cy] 4cy] 4cy] 6cyl
# Levels: 3cyl 4cy] 5cyl 6cyl 8cy]
