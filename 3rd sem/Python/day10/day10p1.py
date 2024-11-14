import pandas as pd

# Create a Pandas Series
data = pd.Series([10, 20, 30, 40], index=['d', 'b', 'a', 'c'])

# Display the Series
print("Series with custom index:")
print(data)

# Fancy indexing example
print("\nFancy indexing example:")
print(data[['d', 'a']])
