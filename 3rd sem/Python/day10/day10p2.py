import pandas as pd

# Define the series
S1 = pd.Series([39, 41, 42, 44], index=['A', 'B', 'C', 'D'])
S2 = pd.Series([10, 10, 10, 10], index=['A', 'B', 'D', 'F'])

# a. S1[:2] * 100
print("Output of S1[:2] * 100:")
print(S1[:2] * 100)

# b. S1 * S2
print("\nOutput of S1 * S2:")
print(S1 * S2)

# c. S2[::-1] * 10
print("\nOutput of S2[::-1] * 10:")
print(S2[::-1] * 10)
