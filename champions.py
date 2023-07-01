import sys
input =sys.stdin.readline

def bsearch(v):
    lo = 0
    hi = n-1
    ret = n-1
    while lo <= hi:
        mid = (lo+hi)//2
        if newVals[mid] == v:
            ret = min(ret, mid)
            hi = mid-1
        elif newVals[mid] < v:
            lo = mid+1
        else:
            hi = mid-1
    return ret

n, k = map(int, input().split())

vals = [int(i) for i in input().split()]
newVals = sorted(vals)
score = [bsearch(vals[i]) for i in range(n)]

for i in range(k):
    a, b = map(int, input().split())
    if vals[a-1] > vals[b-1]:
       score[a-1] -= 1
    elif vals[b-1] > vals[a-1]:
        score[b-1] -= 1

print(*score)