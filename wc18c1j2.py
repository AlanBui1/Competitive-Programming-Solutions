# import sys
# input = sys.stdin.readline

def solve():
    n = input()
    flag = 0
    for i in range(5):
        s = input()
        if s == n:
            flag = 1

    if flag:
        print("Y")
    else:
        print("N")

q = 1
for i in range(q):
    solve()