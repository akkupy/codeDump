def display_pattern(rows):
    for i in range(rows, 0, -1):
        # Print spaces before the asterisks
        for j in range(rows - i):
            print(" ", end=" ")

        # Print asterisks
        for k in range(2 * i - 1):
            print("*", end=" ")

        # Move to the next line for the next row
        print()

# Take the number of rows as input
rows = int(input("Enter the number of rows: "))

# Call the function to display the pattern
display_pattern(rows)
