import sys
input = sys.stdin.readline

n = int(input())
lis = [int(i) for i in input().split()]

p1 = 0
p2 = n-1
ans = 0

while p1 < p2:
    if lis[p1] < lis[p2]:
        p1 += 1
        lis[p1] += lis[p1-1]
        ans += 1
    elif lis[p2] < lis[p1]:
        p2 -= 1
        lis[p2] += lis[p2+1]
        ans += 1
    else:
        p1 += 1
        p2 -= 1
print(ans)