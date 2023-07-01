n = int(input())
lis =[int(input()) for i in range(n)]
lis.sort()
ans = 10000000000
for i in range(1, n-1):
    sz = (-lis[i-1] + lis[i] )/2 + (lis[i+1] - lis[i]) /2
    ans = min(ans, sz)
print(ans)