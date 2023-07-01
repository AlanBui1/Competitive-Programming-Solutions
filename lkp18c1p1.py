n, k = map(int, input().split())

lis = [int(i) for i in input().split()]
lis.sort()

if k%lis[0] != 0:
    print(-1)
else:
    ans = 0
    for i in range(n-1, -1,-1):
        ans += k//lis[i]
        k -= (k//lis[i])*lis[i]
    if k!=0:
        print(-1)
    else:

        print(ans)