import pandas as pd

# Define student marks data
data = {
    'Physics': [68, 74, 90, 84],
    'Chemistry': [78, 82, 85, 79],
    'Mathematics': [88, 75, 92, 80]
}
df = pd.DataFrame(data, index=['Student1', 'Student2', 'Student3', 'Student4'])

# Add Biology marks
df['Biology'] = [82, 79, 90, 80]

# Calculate aggregate marks
df['Aggregate'] = df.sum(axis=1)
print("DataFrame with aggregate marks:")
print(df)

# Descriptive statistics
print("\nDescriptive statistics for each subject:")
print(df.describe())
