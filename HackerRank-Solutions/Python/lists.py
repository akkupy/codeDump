if __name__ == '__main__':
    N = int(input())
    lst = []
    final = []

    for i in range(N):
        x = input().split()
        lst.append(x)

    for i in range(len(lst)):
        if lst[i][0] == 'insert':
            x = int(lst[i][1])
            y = int(lst[i][2])
            final.insert(x,y)
        elif lst[i][0] == 'print':
            print(final)
        elif lst[i][0] == 'remove':
            final.remove(int(lst[i][1]))
        elif lst[i][0] == 'append':
            final.append(int(lst[i][1]))
        elif lst[i][0] == 'sort':
            final.sort()
        elif lst[i][0] == 'pop':
            final.pop()
        elif lst[i][0] == 'reverse':
            final.reverse()
