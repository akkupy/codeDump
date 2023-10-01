import sys
from bisect import bisect_left
import time
x=time.time()
f = open("user.out", 'w')
for nums, tar in zip(sys.stdin, sys.stdin):
    a = nums[1:-2].split()
    tar = tar.rstrip()
    t = int(tar)
    # print((a))
    i = bisect_left(a, True, key=lambda x: int(x) >= t)
    print(i if i < len(a) and a[i] == tar else -1, file=f)
y=time.time()
print(y-x)
