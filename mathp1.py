import sys
input=sys.stdin.readline

def gcd(a,b):
    if b==0:
        return a
    return gcd(b, a%b)
    
n = int(input())
a= [int(i) for i in input().split()]

g = abs(a[0])
for i in a:
    g = gcd(g, abs(i))
    
print(g)