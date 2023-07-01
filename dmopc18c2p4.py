import sys
input = sys.stdin.readline
from math import inf
n, m = map(int, input().split())
dmg = [0]+[int(i) for i in input().split()]
L = inf
for i in range(1, n+1):
    if dmg[i] >= m:
        L=1
        break
    dmg[i] += dmg[i-1]

if L == 1:
    print(1)
elif dmg[-1] < m:
    print(-1)

else:
    left=0; right = 1

    while right <= n:
        if dmg[right] - dmg[left] >= m:
            L = min(L, right-left)
            left+=1

        else:
            right+=1

    if L == inf:
        print(-1)
    else:
        print(L)