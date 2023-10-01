class node():
    def __init__(self,x):
        self.next=None
        self.data=x
    def show(head):
        x=head.next
        while x!=None:
            print(x.data, end=" ")
            x=x.next
        print()
    def shown(head,n):
        c=0
        x=head.next
        while c!=n:
            c+=1
            x=x.next
        print(x.data,"comes at {}th position".format(n))
class start():
    def __init__(self):
        self.next=None
        
    def delete(self,a):
        if self.next == None:
            print("no elements in list")
            return None
        if self.next.data == a:
            self.next = self.next.next
            return None
        else:
            x = self
            while x.next!=None and x.next.data != a:
                x = x.next
            if(x.next!=None and x.next.data==a):
                x.next = x.next.next
                return None
            else:
                print("no such element exist")
                
    def reverse(self):
        x=start()
        z=self
        while z.next!=None:
            y=node(z.next.data)
            y.next=x.next
            x.next=y
            z=z.next
        self.next=None
        self.next=x.next
    def search(self, x):
        c = 0
        while self.next is not None:
            if self.next.data == x:
                print("found at:", c)
                return
            self = self.next
            c += 1
        print(x, "doesn't exist")
        
    def size(self):
        c=0
        x=self.next
        while x!=None:
            c+=1
            x=x.next
        print("Size is: ",c)
    def sort(self):
        x = start()
        z = self.next
        while z is not None:
            y = node(z.data)
            z2 = x
            while z2.next is not None and z2.next.data < y.data:
                z2 = z2.next
            y.next = z2.next
            z2.next = y
            z = z.next
        self.next = x.next
    def randominsert(self,x):
        y=self
        c=-1
        while c!=x:
            y=y.next
            c+=1
        z=y.next
        y.next=node(int(input("enter value to be entered: ")))
        y.next.next=z
n=int(input("Enter number of nodes: "))
head=start()
head.next=node(int(input()))
x=head
for i in range(n-1):
    y=node(int(input()))
    y.next=x.next
    x.next=y
node.show(head)
head.delete(int(input()))
node.show(head)
head.reverse()
node.show(head)
head.search(int(input("Enter the element to search: ")))
head.size()
node.shown(head,int(input("enter the index: ")))
head.sort()
node.show(head)
head.randominsert(int(input("enter index: ")))
node.show(head)
