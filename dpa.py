import sys
input = sys.stdin.readline

n = int(input())

arr = [int(i) for i in input().split()]

cost = [0 for i in range(n)]
cost[0] = 0
cost[1] = abs(arr[0]-arr[1])

for i in range(2, n):
    cost[i] = min(cost[i-2]+abs(arr[i-2]-arr[i]), cost[i-1]+abs(arr[i-1]-arr[i]))

print(cost[n-1])