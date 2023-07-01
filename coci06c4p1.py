import sys
input = sys.stdin.readline

def solve():
    n, w, h = map(int, input().split())
    H = (w**2)+(h**2)
    H = H**0.5

    for i in range(n):
        sz = int(input())
        if sz > H:
            print("NE")
        else:
            print("DA")
    
q = 1
for _ in range(q):
    solve()