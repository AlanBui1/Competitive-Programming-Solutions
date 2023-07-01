import sys
input = sys.stdin.readline

def dist(a, b, c, d):
    return ((c-a)*(c-a)) + ((d-b)*(d-b))

def solve():
    x1, y1 = map(int, input().split())
    x2, y2 = map(int, input().split())
    x3, y3 = map(int, input().split())

    ans = int(1e18)
    ans = min(ans, dist(x1,y1,x2,y2))
    ans = min(ans, dist(x1, y1, x3, y3))
    ans = min(ans ,dist(x2,y2,x3,y3))

    print(ans)
solve()