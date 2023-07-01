import sys
input = sys.stdin.readline

n = int(input())
lis = [int(i) for i in input().split()]
half = n

'''
if split at x,

x, x+1, x+2,..., 2n-1, 0, 1, 2,..., x-1

let 2n = 6, x = 4

[4, 5, 0, 1, 2, 3]

let x = 2
[3, 4, 5, 0, 1, 2]
'''
ans = 0
for i in range(n):
    if lis[i] == lis[i+half]:
        ans += 1
print(ans)