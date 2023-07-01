import sys
input = sys.stdin.readline

def gcd(a, b):
    if b == 0:
        return a
    return gcd(b, a%b)

def solve():
    a, b, n = map(int, input().split())

    pos = [0 for i in range(n+1)]

    pos[0] = 1

    for i in range(n+1):
        if i-a >= 0:
            pos[i] |= pos[i-a]
        if i-b >= 0:
            pos[i] |= pos[i-b]

    if pos[n]:
        print("YES")
    else:
        print("NO")
    
q = int(input())
for _ in range(q):
    solve()