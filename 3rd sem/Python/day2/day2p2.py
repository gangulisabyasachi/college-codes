# Write a program add.py that takes 2 numbers as command line arguments and prints its sum.

import sys

if len(sys.argv) != 3:
    print("Usage: python add.py <num1> <num2>")
else:
    num1 = int(sys.argv[1])
    num2 = int(sys.argv[2])
    print("Sum:", num1 + num2)

'''
Output
D:\code\college codes\3rd sem\Python\day2>python day2p2.py 5 6
Sum: 11
'''