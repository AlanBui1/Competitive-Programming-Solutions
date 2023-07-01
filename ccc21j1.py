import sys
input = sys.stdin.readline

def solve():
    b = int(input())
    p = 5*b-400
    print(p)
    if p < 100:
        print(1)
    elif p == 100:
        print(0)
    else:
        print(-1)
    
q = 1
for _ in range(q):
    solve()