n, m = map(int, input().split())

if m == n-1:
    for i in range(2, n+1):
        print(1, i)

else:
    adj = [[0 for i in range(1+n)] for k in range(n+1)]
    for i in range(1, n+1):
        adj[i][i] = 1
    for i in range(2, n+1):
        print(1, i)
        adj[1][i] = 1
        adj[i][1] = 1

    m -= n-1
    cur = 2
    
    for i in range(1, n+1):
        for k in range(1, n+1):
            if not adj[i][k]:
                adj[i][k] = 1
                adj[k][i] = 1
                print(i, k)
                m -= 1
            if m <= 0:
                break
        if m <= 0:
            break