import sys
input = sys.stdin.readline

def solve():
    h = int(input())
    s = int(input())
    q = int(input())

    for i in range(q):
        h -= s

        print(h)
    


q = 1
for i in range(q):
    solve()