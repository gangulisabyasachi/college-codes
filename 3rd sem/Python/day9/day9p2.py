# q2.py
import numpy as np

# 1D to 2D reshape
array_1d = np.array([1, 2, 3, 4, 5])
reshaped_2d = array_1d.reshape(5, 1)
print("Reshaped 1D to 2D:\n", reshaped_2d)

# 2D to 3D reshape
array_2d = np.array([[1, 2, 3], [4, 5, 6]])
reshaped_3d = array_2d.reshape(2, 1, 3)
print("\nReshaped 2D to 3D:\n", reshaped_3d)

# 2D into a different shape
reshaped_2d_diff = array_2d.reshape(3, 2)
print("\nReshaped 2D to different shape:\n", reshaped_2d_diff)
