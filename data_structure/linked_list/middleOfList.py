# THIS CODE IS CONTRIBUTED BY ARUN HIREMATH
"""
Python program to Find the Middle of a Linked List:

-The std approach to finding the middle node of a linked list is to use two pointers: 
-a slow pointer (moves one step at a time) and a fast pointer (moves two steps at a time). 
-By the time the fast pointer reaches the end of the list, the slow pointer will be at the middle. 
-To handle the case of an even number of elements, we can return the second middle element by adjusting the starting position of the slow pointer.

Time complexity: O(N) The algorithm iterates through the linked list once. The fast ptr moves 2 steps at a time, so the total no. of iterations is proportional to the length of the list.
Space complexity: O(1) The algorithm uses only a constant amount of extra space
"""
class ListNode:
    def __init__(self, value=0, next=None):
        self.value = value
        self.next = next

def find_middle(head):
    # Initialize slow and fast pointers to the head of the list
    slow = fast = head

    # Move the fast pointer two steps at a time and the slow pointer one step at a time
    while fast is not None and fast.next is not None:
        slow = slow.next
        fast = fast.next.next

    # At this point, the slow pointer is at the middle (or second middle for even length)
    return slow.value

# Creating a linked list: 1 -> 2 -> 3 -> 4 -> 5
head = ListNode(1, ListNode(2, ListNode(3, ListNode(4, ListNode(5)))))

# Finding the middle of the linked list
middle_value = find_middle(head)

# Displaying the middle value
print("Middle value of Linkedlist: ", middle_value)
