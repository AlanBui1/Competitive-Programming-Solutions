from decimal import *
getcontext().prec = 20

n = int(input())

lis = [Decimal(input()) for i in range(n)]

while True:
    op = int(input())
    if op == 77:
        break

    elif op == 88:
        k = int(input())
        k -= 1
        lis = lis[:k]+[lis[k]+lis[k+1]]+lis[k+2:]

    elif op == 99:
        k = int(input())
        k -= 1
        perc = Decimal(input())
        lis = lis[:k]+[Decimal(lis[k]*perc/100), Decimal(lis[k]*(100-perc)/100)]+lis[k+1:]
       
    # print(lis)
        
def rounded(a):
    if a%1 >= 0.5:
        return int(a)+1
    return int(a)
for i in range(len(lis)-1):
    print(rounded(lis[i]), end=" ")

print(rounded(lis[-1]))