import sys; input = sys.stdin.readline
from math import ceil
n, m, h = map(int, input().split())

ans = 0

lis = [int(input()) for i in range(n)]

for i in range(n-2, -1, -1):
    start = lis[i]
    if lis[i+1] - lis[i] > h:
        lis[i] +=  ceil(((lis[i+1] - lis[i])-h)/m)*m
        ans +=  (lis[i]-start)/m

print(int(ans))