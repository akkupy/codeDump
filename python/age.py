# input age
age = int(input("Enter Age : "))

# condition to check voting eligibility
status="Eligible" if age>=18 else "Not Eligible" 
print(f"You are {status} for Vote.")
