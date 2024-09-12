def divide_numbers():
    try:
        # Prompt the user to enter two numbers separated by a comma
        user_input = input("Enter two numbers separated by a comma (e.g., 5,2): ")
        
        # Split the input string to extract the numbers
        num1_str, num2_str = user_input.split(',')
        
        # Convert the extracted strings to integers
        number1 = int(num1_str.strip())
        number2 = int(num2_str.strip())
        
        # Perform the division
        result = number1 / number2
        
        # Display the result
        print(f"The result of {number1} divided by {number2} is {result}.")
    
    except ZeroDivisionError:
        print("Error: Division by zero is not allowed.")
    
    except ValueError:
        print("Error: Please enter valid integers separated by a comma.")
    
    except SyntaxError:
        print("Error: Please ensure the numbers are separated by a comma.")

divide_numbers()


# output
# Enter two numbers separated by a comma (e.g., 5,2): 10,5
# The result of 10 divided by 5 is 2.0.