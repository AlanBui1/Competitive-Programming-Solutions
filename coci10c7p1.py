n = int(input())

lis = [10000000 for i in range(n+1)]
lis[0] = 0

for i in range(3, n+1, 3):
    lis[i] = lis[i-3] + 1

for i in range(5, n+1, 1):
    if lis[i-5] != -1:
        lis[i] = min(lis[i], lis[i-5] + 1)

if lis[-1] == 10000000:
    print(-1)
else:
    print(lis[-1])