import pandas as pd

# Create DataFrame with missing values
df_missing = pd.DataFrame({
    'A': [1, 2, None, 4],
    'B': [None, 5, 6, None],
    'C': [7, 8, 9, None]
})

# Method 1: Fill missing values with a constant
df_filled1 = df_missing.fillna(0)
print("Filled DataFrame (method 1 - fill with 0):")
print(df_filled1)

# Method 2: Fill missing values with column mean
df_filled2 = df_missing.fillna(df_missing.mean())
print("\nFilled DataFrame (method 2 - fill with column mean):")
print(df_filled2)

# Create population data frame
population_data = {
    '2020': [3.0, 1.5, 2.0],
    '2019': [2.9, 1.4, 1.9],
    '2018': [2.85, 1.468, 1.998]
}
cities = ['City1', 'City2', 'City3']
population_df = pd.DataFrame(population_data, index=cities)

# Calculate average population for each city
population_df['Average'] = population_df.mean(axis=1)
print("\nPopulation DataFrame with average population:")
print(population_df)
