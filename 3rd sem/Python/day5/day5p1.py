# Define the path to the file
file_path = '/Users/sabyasachiganguli/Desktop/code/college codes/3rd sem/Python/day5/file1.txt'
# Initialize counters
line_count = 0
char_count = 0
# Open the file and process it line by line
with open(file_path, 'r') as file:
    for line in file:
        line_count += 1 # Increment the line count
        char_count += len(line) # Add the length of the line to the character count
# Print the results
print(f"Number of lines: {line_count}")
print(f"Number of characters: {char_count}")

# output
# Number of lines: 2
# Number of characters: 25