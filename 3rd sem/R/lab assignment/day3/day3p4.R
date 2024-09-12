# Read the file “Assocclass24.csv”. Answer the following questions:
#     (a) Find out the number of columns and their names. How many rows are there?
#     (b) How many are male customers and how many are female customers?
#     (c) How many “Middle” aged customers buy milk and diaper?
#     (d) Compute the percentage of transactions that buy milk, bread and diaper together.

# Read the CSV file
df <- read.csv("/Users/sabyasachiganguli/Desktop/code/college codes/3rd sem/R/lab assignment/pdf/Assocclass24.csv")

# (a) Number of columns, their names, and number of rows
num_columns <- ncol(df)
column_names <- colnames(df)
num_rows <- nrow(df)

cat("Number of columns:", num_columns, "\n")
cat("Column names:", column_names, "\n")
cat("Number of rows:", num_rows, "\n")

# (b) Count of male and female customers
gender_count <- table(df$Sex)
cat("Male customers:", gender_count["M"], "\n")
cat("Female customers:", gender_count["F"], "\n")

# (c) Middle-aged customers buying milk and diaper
middle_aged_milk_diaper <- sum(df$Age == "Middle" & df$Milk == 1 & df$Diaper == 1)
cat("Middle aged customers buying milk and diaper:", middle_aged_milk_diaper, "\n")

# (d) Percentage of transactions buying milk, bread, and diaper together
total_transactions <- nrow(df)
milk_bread_diaper_transactions <- sum(df$Milk == 1 & df$Bread == 1 & df$Diaper == 1)
percentage_milk_bread_diaper <- (milk_bread_diaper_transactions / total_transactions) * 100
cat("Percentage of transactions buying milk, bread, and diaper together:", percentage_milk_bread_diaper, "%\n")
cat("Support:", percentage_milk_bread_diaper, "%\n")
milk_bread_transactions <- sum(df$Milk == 1 & df$Bread == 1)
confidence <- (milk_bread_diaper_transactions / milk_bread_transactions) * 100
cat("Confidence:", confidence, "%\n")

# output
# Number of columns: 9
# Column names: Milk Bread Coffee Beer Diaper T Age Income Sex
# Number of rows: 36
# Male customers: 18
# Female customers: 18
# Middle aged customers buying milk and diaper: 4
# Percentage of transactions buying milk, bread, and diaper together: 22.22222 %
# Support: 22.22222 %
# Confidence: 47.05882 %