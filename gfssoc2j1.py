import sys
input = sys.stdin.readline

def solve():
    a = int(input())

    n = int(input())
    for _ in range(n):
        v = int(input())
        if abs(a-v) > 100:
            print("go away! 3:<")
        else:
            print("fite me! >:3")
    


q = 1
for i in range(q):
    solve()