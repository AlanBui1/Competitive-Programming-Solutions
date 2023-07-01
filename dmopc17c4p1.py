import sys
input = sys.stdin.readline
n, q= map(int, input().split())

lis = [0 for i in range(n+1)]

for i in range(q):
    x, y= map(int, input().split())
    lis[x] += 1
    lis[y] -= 1
    
lis.append(0)
p = 0
for i in range(n):
    lis[i] += lis[i-1]
    if lis[i] == 0:
        p += 1   
        
b = n-p

print(p, b)