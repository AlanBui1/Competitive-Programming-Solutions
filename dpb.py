import sys
input = sys.stdin.readline
from math import inf

n, k = map(int, input().split())
arr = [int(i) for i in input().split()]
cost = [inf for i in range(n)]
cost[0] = 0
cost[1] = abs(arr[1]-arr[0])

for i in range(2, n):
    for j in range(k+1):
        if i-j<0:
            break

        cost[i] = min(cost[i], cost[i-j]+abs(arr[i]-arr[i-j]))

print(cost[n-1])