# Kolkata college wants to recognize the department which has succeeded in getting the maximum number of placements for this academic year. The departments that have participated in the recruitment drive are CSE,ECE, MECH. Help the college find the department getting maximum placements. Check for all the possible output given in the sample snapshot
# Note : If any input is negative, the output should be “Input is Invalid”. If all department has equal number of placements, the output should be “None of the department has got the highest placement”.

# Sample Input 1:
# Enter the no of students placed in CSE:90
# Enter the no of students placed in ECE:45
# Enter the no of students placed in MECH:70
# Sample Output 1:
# Highest placement CSE

# Sample Input 2:
# Enter the no of students placed in CSE:55
# Enter the no of students placed in ECE:85
# Enter the no of students placed in MECH:85
# Sample Output 2:
# Highest placement ECE MECH

# Sample Input 3:
# Enter the no of students placed in CSE:0
# Enter the no of students placed in ECE:0
# Enter the no of students placed in MECH:0
# Sample Output 3:
# None of the department has got the highest placement

#  Sample Input 4:
# Enter the no of students placed in CSE:10
# Enter the no of students placed in ECE:-50
# Enter the no of students placed in MECH:40
# Sample Output 4:
# Input is Invalid

cse = int(input("Enter the no of students placed in CSE: "))
ece = int(input("Enter the no of students placed in ECE: "))
mech = int(input("Enter the no of students placed in MECH: "))

if cse < 0 or ece < 0 or mech < 0:
    print("Input is Invalid")
else:
    max_placements = max(cse, ece, mech)

    if cse == ece == mech:
        print("None of the department has got the highest placement")
    else:
        if cse == max_placements:
            print("Highest placement CSE")
        if ece == max_placements:
            print("Highest placement ECE")
        if mech == max_placements:
            print("Highest placement MECH")

# Output
# Enter the no of students placed in CSE: 55
# Enter the no of students placed in ECE: 85
# Enter the no of students placed in MECH: 85
# Highest placement ECE
# Highest placement MECH
