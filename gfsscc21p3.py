n, k = map(int, input().split())
lis= [int(input()) for i in range(n)]

lis.sort()

ans = 0
for i in range(n):
    if k - lis[i] >= 0:
        k -= lis[i]
        ans+=1
        
print(ans)