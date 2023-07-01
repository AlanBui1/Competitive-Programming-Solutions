import sys
input = sys.stdin.readline

n = int(input())
lis = [[int(i) for i in input().split()]for k in range(n)]

ans = int(1e10)
visited = [False for i in range(1 << 11)]
def solve(add, mult, mask, first):
    global ans
    if visited[mask]:
        return
    visited[mask] = True
    if not first:
        ans = min(ans, abs(add-mult))

    for i in range(n):
        if first:
            solve(lis[i][1], lis[i][0], mask|(1<<i), False)
        else:
            if not mask & (1 << i):
                solve(lis[i][1]+add, lis[i][0]*mult, mask | (1<<i), first)

solve(0, 1, 0, True)
print(ans)