import sys
input = sys.stdin.readline

def solve():
    n = int(input())
    highest= -1
    name = ""
    for i in range(n):
        tag = input()
        mon = int(input())
        if mon > highest:
            highest= mon
            name = tag

    print(name)
    
q = 1
for _ in range(q):
    solve()