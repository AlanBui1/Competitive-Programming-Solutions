n = int(input())
closest = -1
ans = []
for i in range(n):
    x, y = map(int, input().split())
    dist = (x*x) + (y*y)
    if dist > closest:
        closest = dist
        ans = [x, y]
        
print(*ans)