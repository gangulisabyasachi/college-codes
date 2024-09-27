install.packages("readxl")
install.packages("class")
install.packages("caTools")

library(class)
library(caTools)
library(readxl)

data <- read_excel("/Users/sabyasachiganguli/Desktop/code/college codes/3rd sem/R/lab assignment/pdf/RidingMowers larger dataset.xls")

features <- data[, 1:2]
target <- data[, 3]

data_combined <- data.frame(features, Ownership = target)

set.seed(123)
split <- sample.split(data_combined$Ownership, SplitRatio = 0.7)
train_cl <- subset(data_combined, split == TRUE)
test_cl <- subset(data_combined, split == FALSE)

euclidean <- function(p1, p2) {
  sqrt(sum((p1 - p2)^2))
}

knn1 <- function(train_data, test_point, k) {
  distances <- numeric(nrow(train_data))
  
  for (i in 1:nrow(train_data)) {
    distances[i] = euclidean(train_data[i, 1:2], test_point)
  }
  
  train_data$distances <- distances
  train_data <- train_data[order(train_data$distances),]
  df <- train_data[1:k, 3]
  
  return(as.character(names(which.max(table(df)))))
}

knn2 <- function(train_data, test_data, k) {
  predictions <- character(nrow(test_data))
  
  for (i in 1:nrow(test_data)) {
    predictions[i] = knn1(train_data, test_data[i, 1:2], k)
  }
  
  test_data$pred <- predictions
  
  misClassError <- mean(test_data$pred != test_data$Ownership)
  print(paste('Accuracy =', 1 - misClassError))
  
  cm <- table(test_data$Ownership, test_data$pred)
  print(cm)
}

knn2(train_cl, test_cl, 3)
