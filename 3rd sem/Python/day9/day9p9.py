# q9.py
import numpy as np

# Create two 3x3 matrices
matrix1 = np.array([[1, 2, 3], [4, 5, 6], [7, 8, 9]])
matrix2 = np.array([[9, 8, 7], [6, 5, 4], [3, 2, 1]])

print("\nMatrix1:\n", matrix1)
print("Matrix2:\n", matrix2)

# Matrix operations
print("\nMatrix Addition:\n", np.add(matrix1, matrix2))
print("\nMatrix Subtraction:\n", np.subtract(matrix1, matrix2))
print("\nMatrix Multiplication:\n", np.multiply(matrix1, matrix2))
print("\nMatrix Division:\n", np.divide(matrix1, matrix2))

# Transpose
print("\nTranspose of Matrix1:\n", np.transpose(matrix1))
