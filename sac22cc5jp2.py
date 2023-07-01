n = int(input())
ans = 0
for i in range(n):
    m, o = map(int, input().split())
    if m > o:
        ans += 1
print(ans)