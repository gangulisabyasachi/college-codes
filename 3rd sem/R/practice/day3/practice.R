# 1. Creating a Data Frame
friend.data <- data.frame(friend_id = c(1:5), 
                          friend_name = c("Sachin", "Sourav", "Dravid", "Sehwag", "Dhoni"))

# Print the data frame
print(friend.data)

# 2. Summary of the Data Frame
print(summary(friend.data))

# 3. Extracting a Column from the Data Frame
result <- data.frame(friend.data$friend_name)
print(result)

# 4. Expanding the Data Frame
friend.data$location <- c("Kolkata", "Delhi", "Bangalore", "Hyderabad", "Chennai")

# Print the modified data frame
print(friend.data)

# 5. Combining Data Frames Vertically and Horizontally
dataframe1 <- data.frame(Name = c("Juan", "Alcaraz"), Age = c(22, 15))
dataframe2 <- data.frame(Name = c("Yiruma", "Bach"), Age = c(46, 89))

# Combine two data frames vertically using rbind()
updated <- rbind(dataframe1, dataframe2)
print(updated)

# 6. Using which() Function
index <- which(updated$Name == "Juan")

# Access and modify the data at that index
print(updated[index, ])
print(updated[index, "Age"])

# Modify the age of Juan
updated[index, "Age"] <- 24
print(updated)

# 7. Data Frame vs List
friend <- data.frame(friend_id = c(1:5), 
                     friend_name = c("Sachin", "Sourav", "Dravid", "Sehwag", "Dhoni"))
print(friend)

friendlist <- list(friend_id = c(1:5), 
                   friend_name = c("Sachin", "Sourav", "Dravid", "Sehwag", "Dhoni"))
print(friendlist)

# Check types and classes
print(typeof(friend))    # "list"
print(class(friend))     # "data.frame"
print(typeof(friendlist)) # "list"
print(class(friendlist))  # "list"

# 8. Working with CSV File
file1 <- read.csv("/Users/sabyasachiganguli/Desktop/code/college codes/3rd sem/R/practice/pdf/college-perf(day 3).csv")

# Print the first few rows
print(head(file1))

# Check class and structure of the file
print(typeof(file1))   # "list"
print(class(file1))    # "data.frame"

# Number of rows and columns
print(length(file1))   # Number of columns
print(nrow(file1))     # Number of rows

# Column names
print(colnames(file1))

# 9. Functions to Extract Information from CSV File
print(mean(file1$SAT))    # Mean SAT score
print(sum(file1$SAT))     # Sum of SAT scores
print(sum(which(file1$SAT > 100))) # Sum of indices where SAT > 100
print(max(file1$SAT))     # Maximum SAT score


# output

# # 1. Creating a Data Frame
# friend.data <- data.frame(friend_id = c(1:5), 
#                           friend_name = c("Sachin", "Sourav", "Dravid", "Sehwag", "Dhoni"))
# > # 1. Creating a Data Frame
# > friend.data <- data.frame(friend_id = c(1:5), 
# +                           friend_name = c("Sachin", "Sourav", "Dravid", "Sehwag", "Dhoni"))
# > # Print the data frame
# > print(friend.data)
#   friend_id friend_name
# 1         1      Sachin
# 2         2      Sourav
# 3         3      Dravid
# 4         4      Sehwag
# 5         5       Dhoni
# > # 2. Summary of the Data Frame
# > print(summary(friend.data))
#    friend_id friend_name       
#  Min.   :1   Length:5          
#  1st Qu.:2   Class :character  
#  Median :3   Mode  :character  
#  Mean   :3                     
#  3rd Qu.:4                     
#  Max.   :5                     
# > # 3. Extracting a Column from the Data Frame
# > result <- data.frame(friend.data$friend_name)
# > print(result)
#   friend.data.friend_name
# 1                  Sachin
# 2                  Sourav
# 3                  Dravid
# 4                  Sehwag
# 5                   Dhoni
# > # 4. Expanding the Data Frame
# > friend.data$location <- c("Kolkata", "Delhi", "Bangalore", "Hyderabad", "Chennai")
# > # Print the modified data frame
# > print(friend.data)
#   friend_id friend_name  location
# 1         1      Sachin   Kolkata
# 2         2      Sourav     Delhi
# 3         3      Dravid Bangalore
# 4         4      Sehwag Hyderabad
# 5         5       Dhoni   Chennai
# > # 5. Combining Data Frames Vertically and Horizontally
# > dataframe1 <- data.frame(Name = c("Juan", "Alcaraz"), Age = c(22, 15))
# > dataframe2 <- data.frame(Name = c("Yiruma", "Bach"), Age = c(46, 89))
# > # Combine two data frames vertically using rbind()
# > updated <- rbind(dataframe1, dataframe2)
# > print(updated)
#      Name Age
# 1    Juan  22
# 2 Alcaraz  15
# 3  Yiruma  46
# 4    Bach  89
# > # 6. Using which() Function
# > index <- which(updated$Name == "Juan")
# > # Access and modify the data at that index
# > print(updated[index, ])
#   Name Age
# 1 Juan  22
# > print(updated[index, "Age"])
# [1] 22
# > # Modify the age of Juan
# > updated[index, "Age"] <- 24
# > print(updated)
#      Name Age
# 1    Juan  24
# 2 Alcaraz  15
# 3  Yiruma  46
# 4    Bach  89
# > # 7. Data Frame vs List
# > friend <- data.frame(friend_id = c(1:5), 
# +                      friend_name = c("Sachin", "Sourav", "Dravid", "Sehwag", "Dhoni"))
# > print(friend)
#   friend_id friend_name
# 1         1      Sachin
# 2         2      Sourav
# 3         3      Dravid
# 4         4      Sehwag
# 5         5       Dhoni
# > friendlist <- list(friend_id = c(1:5), 
# +                    friend_name = c("Sachin", "Sourav", "Dravid", "Sehwag", "Dhoni"))
# > print(friendlist)
# $friend_id
# [1] 1 2 3 4 5

# $friend_name
# [1] "Sachin" "Sourav" "Dravid" "Sehwag" "Dhoni" 

# > # Check types and classes
# > print(typeof(friend))    # "list"
# [1] "list"
# > print(class(friend))     # "data.frame"
# [1] "data.frame"
# > print(typeof(friendlist)) # "list"
# [1] "list"
# > print(class(friendlist))  # "list"
# [1] "list"
# > # 8. Working with CSV File
# > file1 <- read.csv("/Users/sabyasachiganguli/Desktop/code/college codes/3rd sem/R/practice/pdf/college-perf(day 3).csv")
# > # Print the first few rows
# > print(head(file1))
#    SAT  GPA Projects Community Income   Perf
# 1 1380 2.53        1         0  41800 Medium
# 2 1100 3.18        1         5  37600   High
# 3 1110 2.73        2        10  34800    Low
# 4 1180 2.49        3         0  24100 Medium
# 5 1240 2.89        3         5  56000   High
# 6 1140 2.85        2         0  50800    Low
# > # Check class and structure of the file
# > print(typeof(file1))   # "list"
# [1] "list"
# > print(class(file1))    # "data.frame"
# [1] "data.frame"
# > # Number of rows and columns
# > print(length(file1))   # Number of columns
# [1] 6
# > print(nrow(file1))     # Number of rows
# [1] 4000
# > # Column names
# > print(colnames(file1))
# [1] "SAT"       "GPA"       "Projects"  "Community" "Income"    "Perf"     
# > # 9. Functions to Extract Information from CSV File
# > print(mean(file1$SAT))    # Mean SAT score
# [1] 1192.84
# > print(sum(file1$SAT))     # Sum of SAT scores
# [1] 4771360
# > print(sum(which(file1$SAT > 100))) # Sum of indices where SAT > 100
# [1] 8002000
# > print(max(file1$SAT))     # Maximum SAT score
# [1] 1580
# > 