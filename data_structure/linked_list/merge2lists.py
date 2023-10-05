# THIS CODE IS CONTRIBUTED BY ARUN HIREMATH
"""
Python program to Merge Two Sorted Linked Lists:
-The idea is to iterate through both linked lists simultaneously, comparing the values of the current nodes. 
-create a new linked list to store the merged result. At each step, we choose the smaller of the current nodes from the two lists and append it to the merged list.
- Move the pointer of the chosen node to its next element. repeat this process until we reach the end of one of the input lists. 
-If one list becomes empty before the other, directly append the remaining elements from the non-empty list to the merged list.


Time complexity: O(m+n) , where m and n are the lengths of the two input lists.
Space complexity: O(1) as it only creates a few pointers without requiring additional data structures.
"""
class ListNode:
    def __init__(self, value=0, next=None):
        self.value = value
        self.next = next

def merge_sorted_lists(l1, l2):
    # Create a dummy node to simplify the code
    dummy = ListNode()
    current = dummy

    # Iterate until one of the lists becomes empty
    while l1 is not None and l2 is not None:
        if l1.value < l2.value:
            current.next = l1
            l1 = l1.next
        else:
            current.next = l2
            l2 = l2.next

        current = current.next

    # If one list is not empty, append the remaining elements
    if l1 is not None:
        current.next = l1
    elif l2 is not None:
        current.next = l2

    return dummy.next

# Creating two sorted linked lists: 1 -> 3 -> 5 and 2 -> 4 -> 6
list1 = ListNode(1, ListNode(3, ListNode(5)))
list2 = ListNode(2, ListNode(4, ListNode(6)))

# Merging the two sorted lists
merged_list = merge_sorted_lists(list1, list2)

# Displaying the merged list
while merged_list is not None:
    print(merged_list.value, end=" ")
    merged_list = merged_list.next
