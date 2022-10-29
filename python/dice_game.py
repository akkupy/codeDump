import random
import time

def wait():
	time.sleep(2.0)

print("*"*50)
print("Welcome to the Dice Game!")
print("A Game of Luck")
print("*"*50)
print("Roll the die and if you roll a lucky six; You Win! :)")

while (True):
	user_input = input("Press 1 to role Die\n")

	if(user_input == '1' or user_input == 1):
		num = random.randint(1,6)
		print("\nRolling the Die")
		wait()
		if(num == 6):
			print("You got",num)
			print("Yay! You won!\n")
		else:
			print("\nYou got",num,"\nAww! You Lost!\n")

		choice = input("Press Y to Play again\nPress N to Exit Game\n")

		if	(choice == 'Y' or choice == 'y'):
			continue
		elif (choice == 'N' or choice == 'n'):
			break
		else:
			print("\nPlease Enter Y/N.")

	else:
		print("\nNot a valid option")