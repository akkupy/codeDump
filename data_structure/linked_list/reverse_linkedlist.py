#THIS CODE IS CONTRIBUTED BY Arun Hiremath
"""
Reverse the linked list using an iterative approach.
 
- Initialization:
  - Initialize pointers `previous`, `current`, and `next_node`.
  - `previous` starts as `None`.
  - `current` starts at the head of the linked list.

- Process:
  - While `current` is not `None`:
    - Store the next node (`next_node`) to prevent losing the reference.
    - Reverse the link by updating `current.next` to point to `previous`.
    - Move `previous` and `current` pointers to the next pair of nodes.

- Adjustment:
  - After the loop, update the head of the linked list (`self.head`) to the last node (`previous`).

- Complexities:
  - Time Complexity: O(N) (linear time, where N is the number of nodes).
  - Space Complexity: O(1) (constant space, as only a few variables are used).
"""
class ListNode:
    def __init__(self, data):
        self.data = data
        self.next = None

class LinkedList:
    def __init__(self):
        self.head = None

    def reverse_iterative(self):        
        previous = None
        current = self.head

        while current is not None:
            next_node = current.next
            current.next = previous
            previous = current
            current = next_node

        self.head = previous

    def __str__(self): 
       # Returns the linked list in display format.        
        linked_list_str = ""
        temp = self.head

        while temp:
            linked_list_str += str(temp.data) + " "
            temp = temp.next

        return linked_list_str

    def push(self, data):
        """
        Adds new data to the head of the list.
        Args:
        - data: The data to be added.
        """
        new_node = ListNode(data)
        new_node.next = self.head
        self.head = new_node

# Driver code
linkedList = LinkedList()
linkedList.push(20)
linkedList.push(4)
linkedList.push(15)
linkedList.push(85)

print("Given linked list: ")
print(linkedList)

linkedList.reverse_iterative()

print("Reversed linked list: ")
print(linkedList)
