n, m = map(int, input().split())

lis = [int(i) for i in input().split()]
ans = 0
for i in range(n):
    for k in range(i+1, n):
        for j in range(k+1, n):
            if lis[i] + lis[j] + lis[k] <= m:
                ans = max(ans, lis[i] + lis[j] + lis[k])

print(ans)