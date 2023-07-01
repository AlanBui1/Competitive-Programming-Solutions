def gcd(a, b):
    if b == 0:
        return a
    return gcd(b, a%b)

def lcm(a, b):
    return a*b//gcd(a, b)

def solve():
    n = int(input())

    for i in range(n):
        t = int(input())
        if t == 2:
            print(2)
        else:
            print(t-1)

    
solve()