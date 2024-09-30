# q7.py
import numpy as np

# Input array of strings
arr = np.array(['abc', 'def', 'ghi'])
spaced_arr = np.core.defchararray.add(np.core.defchararray.add(arr, ' '), arr)
print("\nArray with spaces between characters:\n", spaced_arr)
