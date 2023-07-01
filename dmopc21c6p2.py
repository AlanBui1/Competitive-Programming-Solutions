n, k = map(int, input().split())
line = input()
lis = []

cur = 0

for i in range(n):
    if line[i] == '0':
        cur += 1
    else:
        lis.append(cur)
        cur = 0
lis.append(cur)
lis.sort(reverse = True)
ans = 0

for i in range(min(len(lis), k)):
    ans += lis[i]

print(ans)