import sys
input = sys.stdin.readline

def works(x):
    arr[0] = x
    for i in range(1, n):
        arr[i] = lis[i-1] - arr[i-1]
        if arr[i] <= 0:
            return False
    return True

n = int(input())
lis = [int(i) for i in input().split()]
arr = [-1 for i in range(n)]

def smallA():
    ans = 0
    
    for i in range(1, min(lis)):
        if works(i):
            ans += 1
    
    print(ans)

def smallN():
    lo = 1
    hi = lis[0] - 1
    
    lowest = int(1e9)+7
    highest = -1
    
    while lo <= hi:
        mid = (lo+hi)//2
    
        if works(mid):
            lowest = min(lowest, mid)
            hi = mid-1
        else:
            lo = mid+1
    
    lo = 1
    hi = lis[0] -1
    
    while lo <= hi:
        mid = (lo+hi)//2
    
        if works(mid):
            highest = max(highest, mid)
            lo = mid+1
        else:
            lo = mid+1
    
    if highest == -1 or lowest == int(1e9)+7:
        print(0)
    else:
        print(highest-lowest+1)

def fullSoln():
    m = min(lis)

    if m == 1:
        print(0)
        return
        
    lo = 1
    hi = m - 1
    
    lowest = int(1e9)+7
    highest = -1
    
    while lo <= hi:
        mid = (lo+hi)//2
    
        if works(mid):
            lowest = min(lowest, mid)
            hi = mid-1
        else:
            lo = mid+1
    
    lo = 1
    hi = m -1
    
    while lo <= hi:
        mid = (lo+hi)//2
    
        if works(mid):
            highest = max(highest, mid)
            lo = mid+1
        else:
            hi = mid-1
    
    if highest == -1 or lowest == int(1e9)+7:
        print(0)
    else:
        print(highest-lowest+1)


if n <= 3:
    smallN()
elif min(lis) <= 10:
    smallA()
else:
    fullSoln()