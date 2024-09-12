# Write a R code to create a data frame from a dictionary of marks in Physics,Chemistry and
# Mathematics of four students, as given below:
#     Name        Physics Chemistry Mathematics
#     Abhishek        88      82         95
#     Usha            81      91         97
#     Shreya          90      85         89
#     Vijay           87      89         91
#  Add another column showing the marks in Biology as 82, 79, 90, 80 respectively.
#  Find the average marks of each student and show it in a new column ‘Average’; the
# computation would be the sum of all marks divided by (number of columns -1)
#  Display in tabular form, the descriptive statistics of all the four subjects and the aggregate.

marks <- data.frame(Name = c("Abhishek", "Usha", "Shreya", "Vijay"), Physics = c(88, 81, 90, 87), Chemistry = c(82, 91, 85, 89), Mathematics = c(95, 97, 89, 91))
print(marks)

marks$Biology <- c(82, 79, 90, 80)
print(marks)

marks$Average <- rowMeans(marks[, 2:5])
print(marks)

summary_stats <- summary(marks[, 2:5])
print(summary_stats)

# output
# Name Physics Chemistry Mathematics
# 1 Abhishek      88        82          95
# 2     Usha      81        91          97
# 3   Shreya      90        85          89
# 4    Vijay      87        89          91
#       Name Physics Chemistry Mathematics Biology
# 1 Abhishek      88        82          95      82
# 2     Usha      81        91          97      79
# 3   Shreya      90        85          89      90
# 4    Vijay      87        89          91      80
#       Name Physics Chemistry Mathematics Biology Average
# 1 Abhishek      88        82          95      82   86.75
# 2     Usha      81        91          97      79   87.00
# 3   Shreya      90        85          89      90   88.50
# 4    Vijay      87        89          91      80   86.75
#     Physics       Chemistry      Mathematics      Biology
#  Min.   :81.0   Min.   :82.00   Min.   :89.0   Min.   :79.00
#  1st Qu.:85.5   1st Qu.:84.25   1st Qu.:90.5   1st Qu.:79.75
#  Median :87.5   Median :87.00   Median :93.0   Median :81.00
#  Mean   :86.5   Mean   :86.75   Mean   :93.0   Mean   :82.75  
#  3rd Qu.:88.5   3rd Qu.:89.50   3rd Qu.:95.5   3rd Qu.:84.00
#  Max.   :90.0   Max.   :91.00   Max.   :97.0   Max.   :90.00