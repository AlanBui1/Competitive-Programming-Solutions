n = int(input())
lis = [int(i) for i in input().split()]
ans = [lis[0]]
a = 0
for i in range(1, n):
    ans.append(lis[i] - lis[i-1])
ans.append(lis[-1])

for i in ans:
    a += abs(i)

print(a//2)