# q3.py
import numpy as np

# i) Zeros array
zeros_array = np.zeros(10)
print("Zeros Array:\n", zeros_array)

# ii) Ones array
ones_array = np.ones((2, 5), dtype=int)
print("\nOnes Array:\n", ones_array)

# iii) Custom array using arange
myarray2 = np.arange(4, 64, 4).reshape(3, 5).astype(float)
print("\nCustom Array using arange:\n", myarray2)

# iv) Tiled array
tiled_array = np.tile(np.array([1, 2, 3]), 3)
print("\nTiled Array:\n", tiled_array)
