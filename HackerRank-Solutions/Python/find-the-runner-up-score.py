if __name__ == '__main__':
    n = int(raw_input())
    arr = map(int, raw_input().split())
    maximum=max(arr)
    while(arr.count(maximum)!=0):
        arr.remove(maximum)
    print max(arr)
