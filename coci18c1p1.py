k = int(input())
n = int(input())

ans = [i+1 for i in range(n-1)]
ans.append(k - sum(ans))

for i in ans:
    print(i)