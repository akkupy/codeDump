import random

def guess_the_number():
    # Generate a random number between 1 and 10
    secret_number = random.randint(1, 10)
    
    attempts = 0
    max_attempts = 3

    print("Welcome to Guess the Number!")
    print("I'm thinking of a number between 1 and 10.")

    while attempts < max_attempts:
        try:
            guess = int(input("Take a guess: "))
        except ValueError:
            print("Please enter a valid number.")
            continue

        attempts += 1

        if guess == secret_number:
            print(f"Congratulations! You guessed the number {secret_number} in {attempts} attempts.")
            break
        elif guess < secret_number:
            print("Too low! Try again.")
        else:
            print("Too high! Try again.")

    else:
        print(f"Sorry, you've run out of attempts. The secret number was {secret_number}.")

if __name__ == "__main__":
    guess_the_number()
