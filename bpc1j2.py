def gcd(a, b):
    if b == 0:
        return a
        
    return gcd(b, a%b)
    
n= int(input())

lis = [int(i) for i in input().split()]

if n > 1:
    G = gcd(lis[0], lis[1])
    for i in range(n-1):
        G = gcd(G, gcd(lis[i], lis[i+1]))
        
    for i in range(n):
        lis[i] //= G
        
    print(*lis)
else:
    print(1)