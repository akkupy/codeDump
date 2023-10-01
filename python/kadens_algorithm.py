'''

N = 5
Arr[] = {1,2,3,-2,5}
Output:
9
Explanation:
Max subarray sum is 9
of elements (1, 2, 3, -2, 5) which 
is a contiguous subarray.

'''

n = int(input())
arr = list(map(int, input().split()))
lmax = 0
gmax = 0

for i in range(n):
    if (arr[i]>(arr[i] + lmax)):
        lmax = arr[i]
    else:
        lmax = lmax + arr[i]
    gmax = max(gmax, lmax)

print(gmax)