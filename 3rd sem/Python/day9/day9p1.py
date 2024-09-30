# q1.py
import numpy as np

# 1D array
array_1d = np.array([1, 2, 3, 4, 5])
print("1D Array:\n", array_1d)
print("Shape:", array_1d.shape)
print("Dimension:", array_1d.ndim)
print("Data type:", array_1d.dtype)

# 2D array
array_2d = np.array([[1, 2, 3], [4, 5, 6]])
print("\n2D Array:\n", array_2d)
print("Shape:", array_2d.shape)
print("Dimension:", array_2d.ndim)
print("Data type:", array_2d.dtype)

# 3D array
array_3d = np.array([[[1, 2], [3, 4]], [[5, 6], [7, 8]]])
print("\n3D Array:\n", array_3d)
print("Shape:", array_3d.shape)
print("Dimension:", array_3d.ndim)
print("Data type:", array_3d.dtype)
