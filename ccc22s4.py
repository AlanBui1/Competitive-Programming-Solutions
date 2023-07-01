import sys
input = sys.stdin.readline

count = 0

n, c = map(int, input().split())
pts = [int(i) for i in input().split()]
a = [0 for i in range(c)]
for i in pts:
    a[i] += 1
for i in a:
    if i:
        count += 1
a+=a

psa1 = [i for i in a]
psa2 = [i*i for i in a]
psa3 = [i*i*i for i in a]

for i in range(1, len(a)):
    psa1[i] += psa1[i-1]
    psa2[i] += psa2[i-1]
    psa3[i] += psa3[i-1]

def sum(psa, L, R):
    if L == 0:
        return psa[R]
    return psa[R] - psa[L-1]

def pairwise(L, R):
    SUM = sum(psa1, L, R)
    SUMSQ = sum(psa2, L, R)
    return (SUM*SUM - SUMSQ)//2

ans = 0



for i in range(c):
    ans += a[i]*pairwise(i+1, c-1)

for i in range(c):
    ans -= a[i]*pairwise(i+1, i+c//2)


print(ans)