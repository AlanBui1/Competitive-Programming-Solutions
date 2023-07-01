import sys
input = sys.stdin.readline

def solve():
    n = int(input())
    highest =0

    while n:
        highest = max(highest, n%10)
        n //= 10

    print(highest)
    
q = 5
for _ in range(q):
    solve()