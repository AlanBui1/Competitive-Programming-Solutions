import sys 
input = sys.stdin.readline
import queue
n, h, p = map(int, input().split())
lvls = [int(i) for i in input().split()]

from math import inf
if h<=p:
    print(max(lvls)*h)

else:
    lvls.sort()
    
    prefix = [0 for i in range(n)]
    prefix[0] = lvls[0]
    for i in range (1, n):
        prefix[i] = prefix[i-1] + lvls[i]
    prefix = [0] + prefix
    lvls = [0] + lvls
    ans = inf
    for i in range(n):
        
        ans = min(ans, h*lvls[i] +(prefix[n] - prefix[i])*p - (p*(n-i)*lvls[i]))
        # print(ans)

    print(ans)