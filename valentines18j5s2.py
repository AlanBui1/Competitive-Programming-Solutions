n, m = map(int, input().split())

orig = [int(input()) for i in range(n)]
deals = [[int(i) for i in input().split()]for k in range(m)]

want = [int(i) for i in input().split()]
pos = []

ans = int(1e18)

def merge(lis1, lis2):
    ret = []
    for i in range(len(lis1)):
        ret.append(lis1[i]+lis2[i])

    return ret

def pos(lis1, lis2):
    for i in range(len(lis1)):
        if lis1[i]+lis2[i] > want[i]:
            return False

    return True

def solve(cur, mask, spent):
    global ans
    cost = spent
    for i in range(len(cur)):
        cost += orig[i]*(want[i]-cur[i])
    ans= min(ans, cost)

    for i in range(m):
        if mask & (1 << i):
            continue

        if pos(cur, deals[i][1:]):
            solve(merge(cur, deals[i][1:]), mask|(1 << i), spent+deals[i][0])

solve([0 for i in range(n)], 0, 0)

print(ans)