import sys
input = sys.stdin.readline

def gcd(a, b):
    if b == 0:
        return a
    return gcd(b, a%b)

def lcm(a, b):
    return a*b//gcd(a, b)

def solve():
    d = int(input())

    for _ in range(d):
        t = int(input())
        s = 0
        for i in range(t):
            s += int(input())
        if s== 0:
            print("Weekend")
        else:
            
            print("Day "+str(_+1)+":", s)
solve()