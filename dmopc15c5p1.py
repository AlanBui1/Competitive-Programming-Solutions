import sys
input = sys.stdin.readline

def gcd(a, b):
    if b == 0:
        return a
    return gcd(b, a%b)

def lcm(a, b):
    return a*b//gcd(a, b)

def solve():
    a = int(input())
    b = int(input())
    x = int(input())
    x -= 1

    L = lcm(a, b)
    print(1+(x//L))
solve()