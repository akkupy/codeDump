# Display the powers of 2 using anonymous function

terms = 10

# Uncomment code below to take input from the user
# terms = int(input("How many terms? "))

# use anonymous function
result = map(lambda x: 2 ** x, range(terms))

print("The total terms are:",terms)
for i, ans in enumerate(result):
   print(f"2 raised to power {i} is {ans}")
