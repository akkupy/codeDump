from random import choice

class Game_Mode:
    def __init__(self, username):
        self.username = username
        self.userscore = 0
        self.compscore = 0

    def start(self):
        gameOptions = ['PAPER', 'SCISSOR', 'ROCK']
        print("\n*************** GAME MODE ******************")
        print(f"{self.username} ({self.userscore}): Computer ({self.compscore})")
        computer_choice = choice(gameOptions)
        user_choice = input("\nChoose your weapon:\n1 for PAPER\n2 for SCISSOR\n3 for ROCK\n")

        if user_choice not in ['1', '2', '3']:
            print("Invalid choice. Please choose 1, 2, or 3.")
            return

        user_choice = gameOptions[int(user_choice) - 1]
        print(f"{self.username} chose {user_choice}")
        print(f"Computer chose {computer_choice}")

        if user_choice == computer_choice:
            print("It's a tie!")
        elif (
            (user_choice == 'PAPER' and computer_choice == 'ROCK') or
            (user_choice == 'ROCK' and computer_choice == 'SCISSOR') or
            (user_choice == 'SCISSOR' and computer_choice == 'PAPER')
        ):
            print(f"{self.username} wins!")
            self.userscore += 1
        else:
            print("Computer wins!")
            self.compscore += 1

def main():
    print("********** WELCOME TO ROCK, PAPER, SCISSORS ***********")
    username = input("Enter your username: ")
    print(f"Welcome, {username}!")

    # Create a single instance of Game_Mode outside the loop
    game = Game_Mode(username)

    while True:
        choice = input("\nPress 1 to START, 2 for RULES, or 3 to QUIT: ")

        if choice == "2":
            print("\nRules: Here's a basic rule for the Paper-Scissors-Rock Game...")
            print("PAPER BEATS ROCK: Paper covers Rock")
            print("ROCK BEATS SCISSOR: Rock crushes Scissors")
            print("SCISSORS BEATS PAPER: Scissors cut Paper")
        elif choice == "1":
            # Start the game with the existing instance
            game.start()
        elif choice == "3":
            print("Thanks for playing!")
            break
        else:
            print("Invalid choice. Please choose 1, 2, or 3.")

if __name__ == "__main__":
    main()
