import sys; input = sys.stdin.readline

n = int(input())
lis = [int(i) for i in input().split()]

if n == 1:
    print(0)
elif n == 2:
    print(sum(lis))
    
else:
    tot = 0
    m = int(1e18)
    for i in range(n):
        tot += lis[i]
        m = min(m, lis[i])
        
    print(tot-m-m+(m*n))