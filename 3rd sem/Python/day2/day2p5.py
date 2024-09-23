# Write a program to determine whether a person is eligible to vote or not . If he/she is not eligible, display how many years are left to be eligible.

age = int(input("Enter your age: "))
if (age >= 18):
    print("You can vote.")
else:
    print("You cannot vote.")
    left = 18-age
    print(f"You can vote after {left} years.")

# Output
# Enter your age: 15
# You cannot vote.
# You can vote after 3 years.
