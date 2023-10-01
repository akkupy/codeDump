# THIS CODE IS CONTRIBUTED BY Arun Hiremath
""" 
Python program to delete nth node from last (2ptr Approach)
Input : 1->2->3->4->5 , N = 2 
Output : 1->2->3->5

Input : 7->8->4->3->2 , N = 1 
Output : 7->8->4->3  

Time complexity: O(N) where N is no of nodes in linked list
Space complexity: O(1) because using constant variables
"""
# structure of node
class Node:
	def __init__(self, key):
		self.data = key
		self.next = None
	

# function to insert node in a linked list
def create(head, x):
	temp = Node(x)
	ptr = head
	if(head is None):
		head = temp
	else:
		while(ptr.next is not None):
			ptr = ptr.next
		ptr.next = temp
	
	return head

# function to remove nth node from last
def removeNthFromEnd(head, B):
	start = Node(-1)
	start.next = head
	fastPtr = start
	slowPtr = start
	# traverse the linkedlist B times
	for i in range(B):
		fastPtr = fastPtr.next
	# increase the slow pointer
	while(fastPtr.next is not None):
		fastPtr = fastPtr.next
		slowPtr = slowPtr.next
	
	# deletion step
	slowPtr.next = slowPtr.next.next
	# return head
	return start.next


# this function prints contents of linked
# list starting from the given node
def display(head):
	temp = head
	while(temp is not None):
		print(temp.data, end=" ")
		temp = temp.next
	

# driver code to test above function
head = None
head = create(head, 1)
head = create(head, 2)
head = create(head, 3)
head = create(head, 4)
head = create(head, 5)

n = 2

print("Linked list before: ")
display(head)

head = removeNthFromEnd(head, 2)
print("\nLinked list after modification: ")
display(head)
