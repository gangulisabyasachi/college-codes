# Write a program that prompts the user to input a Celsius temperature and outputs the equivalent temperature in Fahrenheit.
# The formula to convert the temperature is: F = 9/5 C + 32 where F is the Fahrenheit temperature and C is the Celsius temperature.

celsius = float(input("Enter temperature in Celsius: "))
fahrenheit = (9*celsius+160)/5
print(f"{celsius} degree Celsius = {fahrenheit} degree fahrenheit")

# Output
# Enter temperature in Celsius: 25.3
# 25.3 degree Celsius = 77.54 degree fahrenheit
