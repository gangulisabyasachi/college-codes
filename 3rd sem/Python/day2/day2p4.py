# Write a program which accept two variables through command line and demonstrates the use of the relational operators (<, ==, !=, >, >=, <=) , identity operator(is, is not), membership operators (in, not in).

import sys

# Get command line arguments
var1 = sys.argv[1]
var2 = sys.argv[2]

# Relational Operators
print(f"{var1} < {var2}: {var1 < var2}")
print(f"{var1} == {var2}: {var1 == var2}")
print(f"{var1} != {var2}: {var1 != var2}")
print(f"{var1} > {var2}: {var1 > var2}")
print(f"{var1} >= {var2}: {var1 >= var2}")
print(f"{var1} <= {var2}: {var1 <= var2}")

# Identity Operators
print(f"{var1} is {var2}: {var1 is var2}")
print(f"{var1} is not {var2}: {var1 is not var2}")

# Membership Operators
list1 = [var1, var2]
print(f"{var1} in {list1}: {var1 in list1}")
print(f"{var1} not in {list1}: {var1 not in list1}")

# Output
# D:\code\college codes\3rd sem\Python\day2>python day2p4.py 5 7
# 5 < 7: True
# 5 == 7: False
# 5 != 7: True
# 5 > 7: False
# 5 >= 7: False
# 5 <= 7: True
# 5 is 7: False
# 5 is not 7: True
# 5 in ['5', '7']: True
# 5 not in ['5', '7']: False
