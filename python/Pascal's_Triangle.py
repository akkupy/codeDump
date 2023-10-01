import math
b = 0
flag = 1
while(flag):
    a = int(input("\nEnter the no. of the rows for Pascal's Triangle: "))
    if a>0:
        for i in range(0,a):
            for x in range(a,i,-1):
                print(' '*4,end='')
            for y in range(0,i+1):
                c = int((math.perm(i))/((math.perm(i-b))*math.perm(b)))
                print(c,end='  '*4)
                b+=1
            b = 0
            print()
        flag = 0
    else:
        print("\n!!Invalid Input!!")
