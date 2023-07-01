import sys
input = sys.stdin.readline

def gcd(a, b):
    if b == 0:
        return a
    return gcd(b, a%b)

def lcm(a, b):
    return a*b//gcd(a, b)

def solve():
    n = int(input())
    freq = [0 for i in range(1001)]
    highest = 0
    for i in range(n):
        a = int(input())
        freq[a] += 1
        highest = max(highest, freq[a])
    lis = []
    for i in range(1001):
        if freq[i] == highest:
            lis.append(i)
        
    print(len(lis))
    for i in lis:
        print(i)
    
solve()