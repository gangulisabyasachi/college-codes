'''
Write a program which accepts principal, rate and time(in years) from the user and prints the simple interest.
The formula to calculate simple interest is:
simple interest = principal x rate x time / 100
'''

p = float(input("Enter the principal: "))
r = float(input("Enter the rate(in % per annum): "))
t = int(input("Enter the tenure(in years): "))

simple_interest = (p*r*t)/100

print(f"The Simple Interest is {simple_interest}")

'''
Output
Enter the principal: 109.50
Enter the rate(in % per annum): 7.85
Enter the tenure(in years): 3
The Simple Interest is 25.78725
'''
