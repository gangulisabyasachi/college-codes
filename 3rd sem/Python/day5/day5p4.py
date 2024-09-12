# Define custom exceptions for temperature out of bounds
class TooHot(Exception):
    pass

class TooCold(Exception):
    pass

def check_temperature(temp):
    if temp > 40:
        raise TooHot("Temperature is too hot!")
    elif temp < 20:
        raise TooCold("Temperature is too cold!")
    else:
        print(f"The entered temperature is {temp} degrees.")

# Main program
try:
    # Accept temperature input from the user
    temperature = float(input("Enter the temperature in degrees: "))
    
    # Check the temperature using the custom function
    check_temperature(temperature)

except TooHot as e:
    print(e)

except TooCold as e:
    print(e)

except ValueError:
    print("Please enter a valid numeric temperature.")



# output
# Enter the temperature in degrees: 43
# Temperature is too hot!
