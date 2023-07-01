n, m= map(int, input().split())
arr = [0 for i in range(n+2)]

for _ in range(m):
    a, b = map(int, input().split())
    arr[a] += 1
    arr[b+1] -= 1
    
ans = 0
for i in range(1, n+1):
    arr[i] += arr[i-1]
    if arr[i]%2:
        ans += 1
print(ans)