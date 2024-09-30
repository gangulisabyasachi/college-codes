# q5.py
import numpy as np

# Input number of rows and columns
rows = int(input("Enter number of rows: "))
cols = int(input("Enter number of columns: "))

# Input elements for the matrix
elements = []
for _ in range(rows * cols):
    elements.append(int(input("Enter element: ")))

# Create numpy matrix
m = np.array(elements).reshape(rows, cols)
print("\nMatrix (m):\n", m)

# Sort rows
n = np.sort(m, axis=1)
print("\nSorted rows matrix (n):\n", n)

# Sort columns
p = np.sort(n, axis=0)
print("\nSorted columns matrix (p):\n", p)

# Statistical operation
stat_op = input("Enter statistical operation (min, max, range, mean, median, var, std): ")

if stat_op == "min":
    print("Minimum value:", np.min(p))
elif stat_op == "max":
    print("Maximum value:", np.max(p))
elif stat_op == "range":
    print("Range:", np.ptp(p))
elif stat_op == "mean":
    print("Mean:", np.mean(p))
elif stat_op == "median":
    print("Median:", np.median(p))
elif stat_op == "var":
    print("Variance:", np.var(p))
elif stat_op == "std":
    print("Standard deviation:", np.std(p))
