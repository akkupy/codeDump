a = int(input("\nEnter the no. of rows: "))
for i in range(0,a):
    for x in range(0,a+i):
        print(' ',end='')
    for y in range(0,a-i):
        print('*',end=' ')
    print()