n, t=  map(int, input().split())

lis = [0]+[int(i) for i in input().split()]
orig = lis[:]
for i in range(1, n+1):
    lis[i] += lis[i-1]

ans = 0
MOD = int(1e9)+7

def solve(toRemove):
    global t, n

    

    lo = 1
    hi = n
    ret = 0
    while lo <= hi:
        mid = (lo+hi)//2
        flag = 0
        if mid >= toRemove:
            t += orig[toRemove]
            flag = 1

        if lis[mid] <= t:
            ret = max(ret, mid)
            lo = mid+1
        else:
            hi = mid-1
        if flag:
            t -= orig[toRemove]
    return ret-1
    
for i in range(1, 1+n):
    ans = max(ans, solve(i))

if ans <= 0:
    print(0)
else:
    print(ans%MOD)