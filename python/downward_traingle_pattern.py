# reverse pyramid pattern
n=int(input("enter no. of rows"))

for i in range(1, n+1):
    # printing spaces
    for j in range(i-1):
        print(' ', end='')
    # printing stars
    for j in range(2*(n-i)+1):
        print('*', end='')
    print()