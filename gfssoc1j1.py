n = int(input())
m = int(input())
ans = 0
for i in range(m):
    if int(input()) >= n:
        ans += 1
print(ans)