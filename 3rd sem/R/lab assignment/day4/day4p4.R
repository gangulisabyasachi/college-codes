auto <- read.csv("/Users/sabyasachiganguli/Desktop/code/college codes/3rd sem/R/lab assignment/pdf/auto-mpg.csv", header = TRUE)
table(auto$acceleration)
hist(auto$acceleration, main = "Acceleration Plot", xlab = "Acceleration", col = "darkred", horiz = FALSE)



# output

# > source("/Users/sabyasachiganguli/Desktop/code/college codes/3rd sem/R/lab assignment/day4/day4p4.R", encoding = "UTF-8")
# Warning messages:
# 1: In .External.graphics(C_plot_window, xlim, ylim, log, asp, ...) :
#   "horiz" is not a graphical parameter
# 2: In .External.graphics(C_title, main, sub, xlab, ylab, line, outer,  :
#   "horiz" is not a graphical parameter
# 3: In .External.graphics(C_axis, side, at, as.graphicsAnnot(labels),  :
#   "horiz" is not a graphical parameter
# 4: In .External.graphics(C_axis, side, at, as.graphicsAnnot(labels),  :
#   "horiz" is not a graphical parameter
# warning messages from top-level task callback 'vsc.plot'
# Warning messages:
# 1: In doTryCatch(return(expr), name, parentenv, handler) :
#   "horiz" is not a graphical parameter
# 2: In doTryCatch(return(expr), name, parentenv, handler) :
#   "horiz" is not a graphical parameter
# 3: In doTryCatch(return(expr), name, parentenv, handler) :
#   "horiz" is not a graphical parameter
# 4: In doTryCatch(return(expr), name, parentenv, handler) :
#   "horiz" is not a graphical parameter
# >
