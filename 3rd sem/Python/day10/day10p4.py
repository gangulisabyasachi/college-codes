import pandas as pd

# Creating the Series from a dictionary
data_dict = {'a': 100, 'b': 200, 'c': 300, 'd': 400, 'e': 800}
series = pd.Series(data_dict)
print("Original Series from dictionary:")
print(series)

# Create a new Series with specific indices
new_series = pd.Series(data_dict, index=['d', 'b', 'e', 'a'])
print("\nNew Series with custom indices:")
print(new_series)

# Check for null and non-null values
print("\nChecking for null values:")
print(new_series.isnull())
print("\nChecking for non-null values:")
print(new_series.notnull())
