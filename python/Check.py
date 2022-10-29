

def check(list1, val):
	
	
	for x in list1:

		
		if val>= x:
			return False
	return True
	
	

list1 =[10, 20, 30, 40, 50, 60]
val = 5
if(check(list1, val)):
	print("Yes")
else:
	print("No")

val = 20
if(check(list1, val)):
	print("Yes")
else:
	print("No")
