install.packages("class")
install.packages("caTools")

library(class)
library(caTools)

euclidean <- function(p1, p2) {
  dist1 = sqrt(sum((p1 - p2)^2))
  return(dist1)
}

knn1 <- function(train_data, test_point, k) {
  distances <- numeric(nrow(train_data))
  
  for (i in 1:nrow(train_data)) {
    distances[i] = euclidean(train_data[i, 1:4], test_point)
  }
  
  train_data$distances <- distances
  train_data <- train_data[order(train_data$distances),]
  df <- train_data[1:k, 5]
  
  return(as.character(names(which.max(table(df)))))
}

knn2 <- function(train_data, test_data, k) {
  predictions <- character(nrow(test_data))
  
  for (i in 1:nrow(test_data)) {
    predictions[i] = knn1(train_data, test_data[i, 1:4], k)
  }
  
  test_data$pred <- predictions
  
  misClassError <- mean(test_data$pred != test_data$Species)
  print(paste('Accuracy =', 1 - misClassError))
  
  cm <- table(test_data$Species, test_data$pred)
  print(cm)
}

data(iris)
set.seed(1234)
split <- sample.split(iris$Species, SplitRatio = 0.7)
train_cl <- subset(iris, split == TRUE)
test_cl <- subset(iris, split == FALSE)

print(paste("Training set size:", nrow(train_cl)))
print(paste("Test set size:", nrow(test_cl)))

knn2(train_cl, test_cl, 3)
