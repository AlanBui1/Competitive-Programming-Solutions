import sys
input = sys.stdin.readline

def solve():
    n = int(input())
    want = [int(i) for i in input().split()]

    want.sort()
    if want != [i for i in range(1, n+1)]:
        print(-1)
        return

    print(0)
    
solve()