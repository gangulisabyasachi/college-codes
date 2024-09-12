'''
Write a program that prompts the user to input a Celsius temperature and outputs the equivalent temperature in Fahrenheit.
The formula to convert the temperature is:
C/5=(F-32)/9
Or, F = 9/5 C + 32
Or, F=(9C+160)/5
where F is the Fahrenheit temperature and C is the Celsius temperature.
'''

celsius = float(input("Enter temperature in Celsius: "))
fahrenheit = (9*celsius+160)/5
print(f"{celsius} degree Celsius = {fahrenheit} degree fahrenheit")


'''
Output
Enter temperature in Celsius: 25.9
25.9 degree Celsius = 78.62 degree fahrenheit
'''