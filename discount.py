n, t=  map(int, input().split())
ans = 0
for i in range(n):
    x, y = map(float, input().split())
    if x*(100-y)/100 <= t:
        ans += 1
print(ans)