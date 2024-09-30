# q8.py
import numpy as np

# Input two arrays
arr1 = np.array([1, 2, 3])
arr2 = np.array([2, 3, 1])

# Perform comparisons
print("Equal:", np.equal(arr1, arr2))
print("Not equal:", np.not_equal(arr1, arr2))
print("Greater or equal:", np.greater_equal(arr1, arr2))
print("Greater:", np.greater(arr1, arr2))
print("Less:", np.less(arr1, arr2))
