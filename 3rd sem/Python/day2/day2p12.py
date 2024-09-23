# In a theater, there is a discount scheme announced where one gets a 10% discount on the total cost of tickets when there is a bulk booking of more than 20 tickets, and a discount of 2% on the total cost of tickets if a special coupon card is submitted. Develop a program to find the total cost as per the scheme. The cost of the k class ticket is Rs.75 and q class is Rs.150. Refreshments can also be opted by paying an additional of Rs. 50 per member.
# Hint: k and q and You have to book minimum of 5 tickets and maximum of 40 at a time. If fails display “Minimum of 5 and Maximum of 40 Tickets”. If circle is given a value other than ‘k’ or ‘q’ the output should be “Invalid Input”. The ticket cost should be printed exactly to two decimal places.

# Sample Input 1:
# Enter the no of ticket:35
# Do you want refreshment:y
# Do you have coupon code:y
# Enter the circle:k
# Sample Output 1:
# Ticket cost:4065.25

# Sample Input 2:
# Enter the no of ticket:1
# Sample Output 2:
# Minimum of 5 and Maximum of 40 Tickets

def calculate_ticket_cost():
    # Get the number of tickets
    num_tickets = int(input("Enter the number of tickets: "))

    # Check for valid number of tickets
    if num_tickets < 5 or num_tickets > 40:
        print("Minimum of 5 and Maximum of 40 Tickets")
        return

    # Get the class of tickets
    ticket_class = input("Enter the circle (k/q): ")

    # Check for valid ticket class
    if ticket_class not in ['k', 'q']:
        print("Invalid Input")
        return

    # Get refreshment option
    refreshment = input("Do you want refreshment (y/n): ")

    # Get coupon code option
    coupon_code = input("Do you have coupon code (y/n): ")

    # Calculate ticket cost
    if ticket_class == 'k':
        ticket_cost = 75
    else:
        ticket_cost = 150

    # Add refreshment cost
    if refreshment.lower() == 'y':
        ticket_cost += 50

    # Calculate total cost
    total_cost = num_tickets * ticket_cost

    # Apply bulk booking discount
    if num_tickets > 20:
        total_cost *= 0.9

    # Apply coupon code discount
    if coupon_code.lower() == 'y':
        total_cost *= 0.98

    # Print total cost to two decimal places
    print("Ticket cost: {:.2f}".format(total_cost))


calculate_ticket_cost()

# Output
# Enter the number of tickets: 35
# Enter the circle (k/q): q
# Do you want refreshment (y/n): y
# Do you have coupon code (y/n): y
# Ticket cost: 6174.00
