import sys
input = sys.stdin.readline

def solve():
    r, s = map(int, input().split())
    print(2*s-r)
    
q = 1
for _ in range(q):
    solve()