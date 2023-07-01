import sys; input = sys.stdin.readline

def solve():
    n = int(input())
    for i in range(n):
        a, b = map(int, input().split())
        print(a+b)
solve()