import sys
input = sys.stdin.readline

n = int(input())
lis = [int(i) for i in input().split()]
lis.sort()

ans = 0

for i in range(n):
    lo = i+1
    hi = n-1
    ind = i-1

    while lo <= hi:
        mid = (lo+hi)//2

        if lis[i] * 10 >= 9 * lis[mid]:
            ind = max(ind, mid)
            lo = mid+1
        else:
            hi = mid-1

    if ind != i-1:
        ans += ind - i 

    # print(ind)

print(ans)