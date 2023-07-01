n, h1, h2 = map(int,input().split())
ans= 0
lis = [int(i) for i in input().split()]
for i in range(n):
    if h1 <= lis[i] <= h2:
        ans += 1
print(ans)