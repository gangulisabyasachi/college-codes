'''
Write a program to take day, month, and year as input. Display the output as day/month/year and day.month.year
Example:
Enter day: 16
Enter month: 7
Enter year: 2024
Date is: 16/7/2024
Date is: 16.7.2024
'''

day = int(input("Enter day: "))
month = int(input("Enter month: "))
year = int(input("Enter year: "))

print(f"Date is: {day}/{month}/{year}")
print(f"Date is: {day}.{month}.{year}")


'''
Output
Enter day: 22
Enter month: 07
Enter year: 2024
Date is: 22/7/2024
Date is: 22.7.2024
'''
