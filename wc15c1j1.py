# import sys
# input = sys.stdin.readline

def solve():
    lis = ["WHITE", "RED", "BLUE"]
    for i in range(2):
        lis.remove(input())
    print(lis[0])


q = 1
for i in range(q):
    solve()