# Function to check the validity of the range of the input
def check_range(x):
    if 1 <= x <= 255:
        return True
    else:
        return False

# Function to find the smallest positive integer n such that 2^n >= x
def find_n(x):
    n = 0
    while (2 ** n) < x:
        n += 1
    return n

# Main program
while True:
    try:
        # Take input from the user
        x = int(input("Number of registers in the CPU (1 ≤ x ≤ 255): "))
        
        # Validate the input range
        if check_range(x):
            # Find the smallest n such that 2^n >= x
            n = find_n(x)
            print(f"The number of bits for the Register field in the Instruction format is: {n}")
            break
        else:
            print("Error: The number must be between 1 and 255. Please try again.")
    
    except ValueError:
        print("Invalid input. Please enter an integer.")


# output
# Number of registers in the CPU (1 ≤ x ≤ 255): 16
# The number of bits for the Register field in the Instruction format is: 4