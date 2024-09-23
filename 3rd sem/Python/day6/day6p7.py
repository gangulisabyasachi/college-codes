def is_prime(n):
    if n < 2:
        return False
    for i in range(2, int(n ** 0.5) + 1):
        if n % i == 0:
            return False
    return True

def prime_numbers_generator(n):
    count = 0
    num = 2
    while count < n:
        if is_prime(num):
            yield num
            count += 1
        num += 1

# Taking user input
n = int(input("Enter the number of prime numbers you want to generate: "))
if n > 0:
    print(f"First {n} Prime numbers:")
    print(list(prime_numbers_generator(n)))
else:
    print("Please enter a positive integer.")


# output
# Enter the number of prime numbers you want to generate: 3
# First 3 Prime numbers:
# [2, 3, 5]