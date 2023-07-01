n = int(input())

best = 0
cost = int(1e9)

for i in range(n):
    c, d= map(int, input().split())
    
    if d > best:
        best = d
        cost = c
        
    elif d == best:
        cost = min(cost, c)
print(cost, best)