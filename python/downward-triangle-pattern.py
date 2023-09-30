# Downward Triangle Pattern printing :

n = int(input("Type the number of rows : "))

for i in range(n):

    j=0

    for  j in range(0,i):
        print(" ",end='')

    for  j in range(0,n-i):
        print("* ",end='')

    print()