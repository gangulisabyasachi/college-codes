import matplotlib.pyplot as plt

# Example times collected from running the C program (these values are hypothetical)
sizes = [10000, 100000, 1000000]
times = [1.2, 150222.5, 18000.0]  # Hypothetical values

plt.plot(sizes, times, marker='o')
plt.xlabel('Matrix Size (n x n)')
plt.ylabel('Time (seconds)')
plt.title('Time taken for matrix multiplication')
plt.xscale('log')
plt.yscale('log')
plt.grid(True, which='both', linestyle='--', linewidth=0.5)
plt.show()
# pip install pillow torch opencv-contrib-python pillow pillow
