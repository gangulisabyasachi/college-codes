# Prepare the following data frame.
#     SN Age Name
#     1 27 John
#     2 35 Dora
#     3 23 Martha
# a. Change the age of Martha to 25.
# b. Add a new column State with the data frame.
# c. Delete the Age column.

friend.data <- data.frame(SN = c(1:3), Age = c(27, 35, 23), Name = c("John", "Dora", "Martha"))
print(friend.data)

friend.data[which(friend.data$Name=="Martha"),]$Age=25
print(friend.data)

friend.data$State <- c("WB", "MH", "MP")
print(friend.data)

friend.data <- friend.data[, -2]
print(friend.data)

# Output
#   SN Age   Name
# 1  1  27   John
# 2  2  35   Dora
# 3  3  23 Martha
#   SN Age   Name
# 1  1  27   John
# 2  2  35   Dora
# 3  3  25 Martha
#   SN Age   Name State
# 1  1  27   John    WB
# 2  2  35   Dora    MH
# 3  3  25 Martha    MP
#   SN   Name State
# 1  1   John    WB
# 2  2   Dora    MH
# 3  3 Martha    MP