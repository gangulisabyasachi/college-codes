import os

# Specify the directory where the file should be created
day5_folder = "/Users/sabyasachiganguli/Desktop/code/college codes/3rd sem/Python/day5/"
cities_filename = os.path.join(day5_folder, 'cities.txt')

# Create the file 'cities.txt' in the day5 folder
cities = ["Kolkata", "Delhi", "Mumbai", "Chennai", "Bengaluru", "Patna", 
          "Lucknow", "Hyderabad", "Gandhinagar", "Srinagar"]

with open(cities_filename, 'w') as file:
    for city in cities:
        file.write(city + '\n')

print(f"'cities.txt' has been created in the day5 folder.")

# Function to copy the source file to the destination
def copy_file(source, destination):
    try:
        with open(source, 'r') as src_file:
            content = src_file.read()
            with open(destination, 'w') as dest_file:
                dest_file.write(content)
        print(f"File '{source}' copied to '{destination}' successfully.")
    except FileNotFoundError:
        print("Source file not found. Please check the filename and try again.")

# Automatically use the day5 folder for both source and destination files
source = os.path.join(day5_folder, input("Enter the source file name (e.g., 'cities.txt'): "))
destination = os.path.join(day5_folder, input("Enter the destination file name (e.g., 'cities_copy.txt'): "))

# Copy the source file to the destination
copy_file(source, destination)

# output
# 'cities.txt' has been created in the day5 folder.
# Enter the source file name (e.g., 'cities.txt'): cities.txt
# Enter the destination file name (e.g., 'cities_copy.txt'): cities1.txt
# File '/Users/sabyasachiganguli/Desktop/code/college codes/3rd sem/Python/day5/cities.txt' copied to '/Users/sabyasachiganguli/Desktop/code/college codes/3rd sem/Python/day5/cities1.txt' successfully.