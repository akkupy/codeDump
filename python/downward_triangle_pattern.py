row=int(input("Enter the number of rows:"))
for i in range (row,0,-1):
    for k in range(row,i,-1):
        print(" ",end="")#prints spaces
    for j in range(0,i):
        print("* ",end="")# prints stars
    print("\n")# goes to new line