from math import ceil
n, k = map(int, input().split())

if k == 1:
    print(n-1)
else:
    ans = 0
    cur = 1
    while cur < n:
        if cur >= k:
            ans += ceil((n-cur)/k)
            break
        cur += min(cur, k)
        ans += 1

    print(ans)