# import sys
# input = sys.stdin.readline

def solve():
    c = input()
    line = input()
    print(line)
    print(line.count(c.upper())+line.count(c.lower()))

    
    
q = 1
for _ in range(q):
    solve()