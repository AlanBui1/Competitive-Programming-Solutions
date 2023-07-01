import sys
input = sys.stdin.readline

MOD = (10**9)+7

n, k = map(int, input().split())
A = [int(i) for i in input().split()]
B = [int(i) for i in input().split()]

A.sort(); B.sort()

ans = 0

for i in range(n-1):
    ans += A[i]*B[i]
    ans %= MOD

if k != 0:
    a = A[-1]
    b = B[-1]
    
    if a < b:
        tosub = min(b-a, k)
        k -= tosub
        a += tosub
        
    elif b < a:
        tosub =  min(a-b, k)
        k -= tosub
        b += tosub
 
    if k > 0:
        a += k//2
        b += k-(k//2)
    
    ans += a*b
    ans %= MOD

else:
    ans += (A[-1]*B[-1])
    ans %= MOD

print(ans%MOD)