import sys; input = sys.stdin.readline

def solve():
    n = int(input())
    
    lis = [[int(i) for i in input().split()] for k in range(n)]
    
    bad = 0
    cur = 0
    for i in range(n):
        for k in range(n):
            cur += 1
            if lis[i][k] != cur:
                bad += 1
                
    print(int((bad+1)**0.5))
    
solve()