# Vivek went to a movie with his friends in a theatre and during break time he bought pizzas, puffs and cool drinks. Consider the following prices :
# Rs.100/pizza
# Rs.20/puffs
# Rs.10/cool drink
# Generate a bill for What Vivek has bought.
# Sample Input 1:
# Enter the no of pizzas bought:10
# Enter the no of puffs bought:12
# Enter the no of cool drinks bought:5
# Sample Output 1:
# Bill Details
# No of pizzas:10
# No of puffs:12
# No of cooldrinks:5
# Total price=1290
# ENJOY THE SHOW!!!

pizza_price = 100
puffs_price = 20
cool_drink_price = 10
pizza = int(input("Enter the no of pizzas bought "))
puff = int(input("Enter the no of puffs bought "))
cool = int(input("Enter the no of cool drinks bought "))
print("Bill Details")
pizza_total = pizza*pizza_price
cool_total = cool_drink_price*cool
puff_total = puff*puffs_price
total = puff_total+cool_total+pizza_total
print(f"No of pizzas = {pizza}")
print(f"No of puffs = {puff}")
print(f"No of cooldrinks = {cool}")
print(f"Total price = {total}")
print("ENJOY THE SHOW!!!")

# Output
# Enter the no of pizzas bought 15
# Enter the no of puffs bought 2
# Enter the no of cool drinks bought 14
# Bill Details
# No of pizzas = 15
# No of puffs = 2
# No of cooldrinks = 14
# Total price = 1680
# ENJOY THE SHOW!!!
