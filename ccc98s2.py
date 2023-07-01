def perfect(n):
    factors = []
    for i in range(1, n):
        if n%i == 0:
            factors.append(i)
            
    return sum(factors) == n
    
def sumCubes(n):
    digs = []
    orig = n
    while n:
        digs.append(n%10)
        n//=10
    res = 0
    for i in digs:
        res += i**3
    return res == orig


lis = []
for i in range(1000, 10000):
    if perfect(i):
        lis.append(i)
        
print(*lis)
lis =[]

for i in range(100, 1000):
    if sumCubes(i):
        lis.append(i)
        
print(*lis)