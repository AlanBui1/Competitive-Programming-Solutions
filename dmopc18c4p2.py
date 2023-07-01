import sys; input = sys.stdin.readline;
n = int(input())

arr = [int(i) for i in input().split()]

tot = sum(arr)

dp = [False for i in range(tot+1)]

dp[0] = True

for val in arr:
    for i in range(tot, -1, -1):
        if i-val >= 0:
            dp[i] = True
        else:
            break

for i in range(tot//2, -1, -1):
    if dp[i]:
        print(tot-(i*2))
        break