n = int(input())
lis = [int(i) for i in input().split()]
x=0
ans = 1
sofar = 0

for i in range(n):

    if lis[i] %2 == 0:
        sofar+=lis[i]
    else:
        ans = max(ans, sofar)
        sofar = 0
ans = max(ans, sofar)
print(ans)