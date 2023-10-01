def tower_of_hanoi(n, source, target, auxiliary):
    if n > 0:
        # Move n-1 disks from source to auxiliary peg
        tower_of_hanoi(n - 1, source, auxiliary, target)

        # Move the nth disk from source to target peg
        print(f"Move disk {n} from {source} to {target}")

        # Move the n-1 disks from auxiliary peg to target peg
        tower_of_hanoi(n - 1, auxiliary, target, source)

# Get user input for the number of disks
num_disks = int(input("Enter the number of disks: "))

# Run Tower of Hanoi with user input
tower_of_hanoi(num_disks, 'A', 'C', 'B')
