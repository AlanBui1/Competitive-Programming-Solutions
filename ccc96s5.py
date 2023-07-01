import sys
input = sys.stdin.readline

def solve():
    n = int(input())
    x = [int(i) for i in input().split()]
    y = [int(i) for i in input().split()]
    d = 0

    for i in range(n):
        if y[i] < x[-1]:
            continue
        lo = 0
        hi = n-1
        ind = i
        while lo <= hi:
            mid = (lo+hi)//2
            if x[mid] <= y[i]:
                ind = min(ind, mid)
                hi = mid-1
            else:
                lo = mid+1

        d = max(d, abs(i - ind))
    print("The maximum distance is", d)
t = int(input())

for i in range(t):
    solve()