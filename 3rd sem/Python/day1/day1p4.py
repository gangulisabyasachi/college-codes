'''
Create a variable "ap" and accept "apple price" from user, then print user’s apple price “ap” , its datatype and its memory location, then next reassign apple price to 34, again print apple price and its memory location, finally delete variable "ap" and try to print ap. Hint: Final Output will be like below
NameError: name 'ap' is not defined
'''

ap = int(input("Enter the price of apples: "))
print(f"The price of apple is Rs. {ap}")
print(f"The datatype of {ap} is {type(ap)}")

ap = 34
print(f"The price of apple is now Rs. {ap}")
print(f"The memory location of {ap} is {id(ap)}")

del ap
print(f"Let's try printing {ap}")

'''
Output
Enter the price of apples: 159900
The price of apple is Rs. 159900
The datatype of 159900 is <class 'int'>
The price of apple is now Rs. 34
The memory location of 34 is 140722303925720
Traceback (most recent call last):
  File "d:\code\college codes\3rd sem\Python\day1\day1p4.py", line 13, in <module>
    print(f"Let's try printing {ap}")
                                ^^
NameError: name 'ap' is not defined. Did you mean: 'map'?
'''
