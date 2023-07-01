import sys
input = sys.stdin.readline

n= int(input())
h= [int(i) for i in input().split()]

ans = 0
cnt = 1
for i in range(1, n):
    if h[i] > h[i-1]:
        cnt += 1
    else:
        cnt = 1
    ans = max(ans, cnt)
print(ans)

ans = 0
cnt = 1
for i in range(1, n):
    if h[i] < h[i-1]:
        cnt += 1
    else:
        cnt = 1
    ans = max(ans, cnt)
print(ans)