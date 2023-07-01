import sys
input = sys.stdin.readline

m, n, k = map(int, input().split())
inf = int(1e9)

lis = [int(I) for I in input().split()] 

if n == 1:
    lis.sort()
    lis.reverse()
    ans = 0
    for i in range(k):
        ans += lis[0] + i - lis[i]
    print(ans)

else:
    lis.sort()
    lis.reverse()


    cols = min(n, k//m + (k%m > 0))
    ans = [[0 for i in range(m)] for j in range(cols)]
    cnt = 0

    for i in range(cols):
        if cnt >= k:
            ans[i][0] = inf
        else:
            ans[i][0] = lis[cnt]
        cnt += 1

    for j in range(cols):
        for i in range(1, m):
            if cnt >= k:
                ans[j][i] = inf
            else:
                ans[j][i] = lis[cnt]
            cnt += 1

    finAns = 0
    for i in range(cols):
        for j in range(m):
            finAns += max(0, ans[i][0] + j - ans[i][j])
    print(finAns)