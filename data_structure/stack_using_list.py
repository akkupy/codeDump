class Node:
    def __init__(self, data):
        self.data = data
        self.next = None
class Stack:
    def __init__(self):
        self.top = None

    def is_empty(self):
        return self.top is None

    def push(self, data):
        new_node = Node(data)
        if self.is_empty():
            self.top = new_node
        else:
            new_node.next = self.top
            self.top = new_node

    def pop(self):
        if self.is_empty():
            print("Stack is empty")
        else:
            popped_item = self.top.data
            self.top = self.top.next
            return popped_item

    def peek(self):
        if self.is_empty():
            print("Stack is empty")
        else:
            return self.top.data

    def display(self):
        current = self.top
        if current is None:
            print("Stack is empty")
        else:
            print("Stack:")
            while current:
                print(current.data, end=" -> ")
                current = current.next
            print("None")

def main():
    stack = Stack()

    while True:
        print("\nStack Menu:")
        print("1. Push")
        print("2. Pop")
        print("3. Peek")
        print("4. Display")
        print("5. Quit")

        choice = input("Enter your choice: ")

        if choice == '1':
            data = input("Enter data to push onto the stack: ")
            stack.push(data)
        elif choice == '2':
            popped_item = stack.pop()
            if popped_item is not None:
                print("Popped item:", popped_item)
        elif choice == '3':
            peeked_item = stack.peek()
            if peeked_item is not None:
                print("Top item:", peeked_item)
        elif choice == '4':
            stack.display()
        elif choice == '5':
            print("Exiting the program.")
            break
        else:
            print("Invalid choice. Please try again.")

if __name__ == "__main__":
    main()
