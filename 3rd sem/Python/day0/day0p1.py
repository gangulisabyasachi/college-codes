# print the sum of the digits of a given number


n=int(input("Enter the number "))
sum=0
while(n>0):
    r=n%10
    sum=sum+r
    n=n//10
print("Sum of digits = ", sum)

# Output
# Enter the number 219
# Sum of digits =  12