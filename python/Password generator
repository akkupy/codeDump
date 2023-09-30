import random
import string

def generate_password(length, use_lowercase=True, use_uppercase=True, use_digits=True, use_special_chars=False):
    characters = ''

    if use_lowercase:
        characters += string.ascii_lowercase
    if use_uppercase:
        characters += string.ascii_uppercase
    if use_digits:
        characters += string.digits
    if use_special_chars:
        characters += string.punctuation

    if not characters:
        print("Please select at least one character type.")
        return None

    password = ''.join(random.choice(characters) for _ in range(length))
    return password

if __name__ == "__main__":
    print("Password Generator")

    length = int(input("Enter the length of the password: "))
    use_lowercase = input("Use lowercase letters? (yes/no): ").lower() == "y"
    use_uppercase = input("Use uppercase letters? (yes/no): ").lower() == "y"
    use_digits = input("Use digits? (yes/no): ").lower() == "y"
    use_special_chars = input("Use special characters? (yes/no): ").lower() == "y"

    password = generate_password(length, use_lowercase, use_uppercase, use_digits, use_special_chars)

    if password:
        print(f"Generated Password: {password}")
    else:
        print("Password generation failed.")
