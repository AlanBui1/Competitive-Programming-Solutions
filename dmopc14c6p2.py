import sys 
input = sys.stdin.readline

def solve():
    n = int(input())
    start, q = map(int, input().split())
    orig = start
    cnt = 0
    cur = 0
    for i in range(n-2):
        geton, getoff = map(int, input().split())
        cnt += getoff
        if cur >= getoff:
            x = getoff
        else:
            x = cur
        cur -= x
        getoff -= x
        start -= getoff
        cur += geton
        
    print(max(0, orig-cnt))
    print(start)
        
        
solve()