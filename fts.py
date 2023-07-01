n= int(input())
lis = [int(i) for i in input()]
changes = 0
ans = 0

for i in range(n-1, -1, -1):
    if (changes+lis[i])%2 == 1:
        changes += 1
        ans += 1

print(ans)