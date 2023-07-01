import sys
input = sys.stdin.readline
def solve():
    n = int(input())
    a = [int(i) for i in input().split()]

    found = [0 for i in range(n+1)] 
    for i in a:
        if found[i]:
            print("NO")
            return
        found[i] = 1
    print("YES")


solve()