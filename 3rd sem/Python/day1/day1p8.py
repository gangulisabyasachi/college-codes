'''
Write a program that accepts seconds from keyboard as integer. Your program should convert seconds in hours, minutes and seconds. Your output should like this :
Enter seconds: 13400
Hours: 3
Minutes=43
Seconds=20
'''

seconds = int(input("Enter seconds: "))

hours = seconds // 3600
minutes = (seconds % 3600) // 60
seconds = seconds % 60

print(f"Hours: {hours} \nMinutes: {minutes} \nSeconds: {seconds}")

'''
Output
Enter seconds: 198763
Hours: 55   
Minutes: 12 
Seconds: 43
'''
