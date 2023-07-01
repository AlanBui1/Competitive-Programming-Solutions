import sys
input = sys.stdin.readline

n = int(input())
arr = [int(i) for i in input().split()]
x = sum(arr)
arr = arr+arr
psa = [0]
for i in range(2*n):
    psa.append(psa[-1]+arr[i])
ans= []
def solve(x, e, tot):
    lo = x 
    hi = e
    smallest = int(1e9)
    while lo <= hi:
        mid = (lo+hi)//2

        if psa[mid] - psa[x-1] >= psa[e] - psa[mid-1]:
            smallest = min(smallest, mid)
            hi = mid-1
        else:
            lo = mid+1

    ans.append(abs(tot - (2*min(abs(psa[smallest] - psa[x-1]), abs(psa[smallest-1] - psa[x-1])))))
            

for i in range(n):
    solve(i+1, i+n, x)

print(*ans)