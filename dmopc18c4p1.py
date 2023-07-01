from decimal import *
getcontext().prec = 10

K = int(input())
mx = Decimal(input())

ans = Decimal(0)
for i in range(K):
    lis = [Decimal(i) for i in input().split()]
    myi = mx
    for k in range(1, int(lis[0])+1):
        myi += lis[k]

    ans+=myi
print(Decimal(ans/K))