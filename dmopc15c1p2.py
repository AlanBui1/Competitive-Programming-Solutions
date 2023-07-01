n, l, r = map(int, input().split())
b = [int(i) for i in input().split()]
b.sort(reverse = True)
ans = 0
for i in range(0, n, l):
    if i+r-1 < n:
        ans += b[i+r-1]
print(ans)