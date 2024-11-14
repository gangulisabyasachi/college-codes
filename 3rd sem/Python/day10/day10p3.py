import pandas as pd
import numpy as np

# Define the series
S1 = pd.Series([39, 41, 42, 44], index=['A', 'B', 'C', 'D'])

# Boolean filtering
filtered_S1 = S1[S1 > 40]
print("Filtered Series S1 > 40:")
print(filtered_S1)

# Scalar multiplication and square root
filtered_S1 *= 2
print("\nAfter scalar multiplication:")
print(filtered_S1)

# Applying square root
sqrt_S1 = np.sqrt(filtered_S1)
print("\nAfter applying square root:")
print(sqrt_S1)
