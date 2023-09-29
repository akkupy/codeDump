class Stack:
    def __init__(self):
        self.items = []

    def is_empty(self):
        return len(self.items) == 0

    def push(self, item):
        self.items.append(item)
        print(f"Pushed {item} onto the stack.")

    def pop(self):
        if not self.is_empty():
            popped_item = self.items.pop()
            print(f"Popped {popped_item} from the stack.")
        else:
            print("Stack is empty. Cannot pop.")

    def delete(self, item):
        if item in self.items:
            self.items.remove(item)
            print(f"Deleted {item} from the stack.")
        else:
            print(f"{item} not found in the stack.")

    def traverse(self):
        if not self.is_empty():
            print("Stack elements:")
            for item in reversed(self.items):
                print(item)
        else:
            print("Stack is empty.")

def main():
    stack = Stack()

    while True:
        print("\nStack Menu:")
        print("1. Push")
        print("2. Pop")
        print("3. Delete")
        print("4. Traverse")
        print("5. Quit")

        choice = input("Enter your choice: ")

        if choice == '1':
            item = input("Enter the item to push onto the stack: ")
            stack.push(item)
        elif choice == '2':
            stack.pop()
        elif choice == '3':
            item = input("Enter the item to delete from the stack: ")
            stack.delete(item)
        elif choice == '4':
            stack.traverse()
        elif choice == '5':
            print("Exiting the program.")
            break
        else:
            print("Invalid choice. Please choose a valid option.")

if __name__ == "__main__":
    main()
