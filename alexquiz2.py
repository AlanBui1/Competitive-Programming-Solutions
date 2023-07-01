import sys
input= sys.stdin.readline
q = int(input())
nax = 100005
psa = [0 for i in range(nax)]

def prime(n):
    if n <= 3:
        return n
    if n%2 == 0 or n%3 == 0:
        return 0
    i = 5
    while i*i <= n:
        if n%i == 0:
            return 0
        i+=2
    return n

for i in range(2, nax):
    psa[i] = prime(i)
    
for i in range(1, nax):
    psa[i] += psa[i-1]

for _ in range(q):
    a, b = map(int, input().split())
    print(psa[b] - psa[a-1])