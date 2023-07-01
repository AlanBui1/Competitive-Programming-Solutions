n= int(input())
best = -1
ans = ""
for i in range(n):
    name, r = input().split()
    r = float(r)
    if r > best:
        ans = name
        best = r
print(ans)