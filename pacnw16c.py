import sys
input = sys.stdin.readline

n, k, r = map(int ,input().split())
lis = [0 for i in range(n+1)]

for j in range(k):
    c = int(input())
    lis[c] = 1

p1 = 1
cnt = 0

for i in range(p1, p1+r):
    cnt += lis[i]

p2 = p1+r-1
ans = 0

if cnt == 1:
    if lis[p2] == 0:
        lis[p2] = 1
    else:
        lis[p2-1] = 1
    ans = 1

elif cnt == 0:
    if lis[p2] == 0:
        lis[p2] = 1
        cnt+=1
    if lis[p2-1] == 0:
        lis[p2-1] = 1
        cnt += 1
    if cnt != 2:
        lis[p2-2] = 1
    ans = 2
        
cnt = max(cnt, 2)
while p2 < n:
    p2 += 1
    cnt += lis[p2]
    cnt -= lis[p1]
    p1 +=1

    if cnt < 2:
        lis[p2] += 1
        cnt += 1
        ans += 1

print(ans)