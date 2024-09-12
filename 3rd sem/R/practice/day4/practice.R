# Install necessary packages
install.packages("arules")
install.packages("plotrix")
library(arules)
library(plotrix)

# Load the dataset (make sure the file path is correct)
grocery <- read.csv("/Users/sabyasachiganguli/Desktop/code/college codes/3rd sem/R/practice/pdf/Assocclass24.csv", header = TRUE)

# Summary of the dataset
print(ncol(grocery)) # Number of columns
print(nrow(grocery)) # Number of rows
print(summary(grocery)) # Summary of the dataset

# Step 1: Association Mining (Apriori Algorithm)
# Selecting the first 5 columns for association mining (binary data)
grocery_subset <- grocery[, 1:5]

# Convert the data into a binary format (TRUE/FALSE)
grocery_binary <- data.frame((grocery_subset == 1))

# Apply the Apriori algorithm
brules <- apriori(grocery_binary, parameter = list(support = 0.3, confidence = 0.7))

# Inspect the top rules found
inspect(brules)

# Step 2: Bar Plots

# Example 1: Bar plot for maximum temperatures over 7 days
max.temp <- c(22, 27, 26, 24, 23, 26, 28)
barplot(max.temp, main = "Maximum Temperatures", xlab = "Days", ylab = "Temperature (°C)")

# Example 2: Bar plot for marks
marks <- c(70, 95, 80, 74)
barplot(marks,
        main = "Comparing Marks of 4 Subjects", xlab = "Subjects",
        ylab = "Marks", names.arg = c("English", "Science", "Math", "History"),
        col = "darkred", horiz = FALSE
)

# Example 3: Bar plot for age distribution
age <- c(17, 18, 18, 17, 18, 19, 18, 16, 18, 18)
barplot(table(age),
        main = "Age Count of 10 Students", xlab = "Age", ylab = "Count",
        border = "red", col = "blue", density = 10
)

# Step 3: Exporting Bar Plot to a File
png(file = "age_barplot.png")
barplot(table(age),
        main = "Age Count of 10 Students", xlab = "Age", ylab = "Count",
        border = "red", col = "blue", density = 10
)
dev.off()

# Step 4: Titanic Survival Bar Plot
titanic.data <- data.frame(First = c(122, 203), Second = c(167, 118), Third = c(528, 178), Crew = c(673, 212))
barplot(as.matrix(titanic.data), main = "Survival of Each Class", xlab = "Class", col = c("red", "green"))
legend("topleft", c("Not survived", "Survived"), fill = c("red", "green"))

# Step 5: Histogram for age distribution
hist(age, main = "Histogram of Ages", xlab = "Age", col = "lightblue", border = "black")

# Step 6: Pie Charts

# Simple Pie Chart
x <- c(21, 62, 10, 53)
labels <- c("London", "New York", "Singapore", "Mumbai")
png(file = "city_pie_chart.png")
pie(x, labels, main = "City Pie Chart")
dev.off()

# Pie Chart with Title and Colors
png(file = "city_title_colours.jpg")
pie(x, labels, main = "City Pie Chart with Colors", col = rainbow(length(x)))
dev.off()

# Step 7: 3D Pie Chart using plotrix
lbl <- c("London", "New York", "Singapore", "Mumbai")
png(file = "3d_pie_chart.jpg")
pie3D(x, labels = lbl, explode = 0.1, main = "Pie Chart of Cities")
dev.off()
