# q6.py
import numpy as np

# Input elements for the 4x3 matrix
arr = np.array([int(input("Enter element: ")) for _ in range(12)]).reshape(4, 3)
print("\nMatrix (arr):\n", arr)

# Find column mean
col_mean = np.mean(arr, axis=0)
print("\nColumn mean (cm):\n", col_mean)

# Demeaning the columns
demean = arr - col_mean
print("\nDemeaned matrix:\n", demean)
