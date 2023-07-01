n = int(input())
lis = [int(i) for i in input().split()]

ans = 0
for i in range(n):
    if lis[i] == lis[n-1-i]:
        continue
    
    ans += 1
print(ans)