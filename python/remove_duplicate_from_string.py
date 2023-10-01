string=input("Enter the string : ")
p=""
for char in string:
    if char not in p:
        p=p+char
print(p)