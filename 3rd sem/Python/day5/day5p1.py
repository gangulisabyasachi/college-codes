def count_lines_and_characters(filename):
    try:
        with open(filename, 'r') as file:
            lines = file.readlines()
            line_count = len(lines)
            char_count = sum(len(line) for line in lines)
            print(f"Number of lines: {line_count}")
            print(f"Number of characters: {char_count}")
    except FileNotFoundError:
        print("File not found. Please check the filename and try again.")

filename = input("Enter the filename (with path if not in current directory): ")
count_lines_and_characters(filename)


# output
# Enter the filename (with path if not in current directory): /Users/sabyasachiganguli/Desktop/code/college codes/3rd sem/Python/day5/file1.txt
# Number of lines: 2
# Number of characters: 25