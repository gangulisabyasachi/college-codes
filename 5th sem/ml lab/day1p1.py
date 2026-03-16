from sklearn.tree import DecisionTreeClassifier

# Training data
X = [[0, 0], [0, 1], [1, 0], [1, 1]]
y = [0, 0, 0, 1]

# Create and train the classifier
clf = DecisionTreeClassifier()
clf.fit(X, y)

# Take user input
a = int(input("Enter first binary input (0 or 1): "))
b = int(input("Enter second binary input (0 or 1): "))

# Predict using the trained model
prediction = clf.predict([[a, b]])

# Output result
print(f"Predicted Output: {prediction[0]}")
