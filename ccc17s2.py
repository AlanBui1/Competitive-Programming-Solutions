n = int(input())
lis = [int(i) for i in input().split()]
lis.sort()
ans =[]
lo = lis[ : n//2+(n%2)]
lo.reverse()
hi = lis[n//2+(n%2):]
for i in range(n//2):
    ans.append(lo[i])
    ans.append(hi[i])
if n%2:
    ans.append(lo[-1])
print(*ans)