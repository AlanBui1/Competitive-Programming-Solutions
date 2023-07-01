import sys; input = sys.stdin.readline

n = int(input())
for i in range(n):
    m = int(input())
    factors = []
    orig = m
    
    while m%2 == 0:
        m//=2
        factors.append(2)
        
    while m%3 == 0:
        m//=3
        factors.append(3)
    
    for cur in range(3, int(orig**0.5)+1, 2):
        if m <= 1:
            break
        while m%cur == 0:
            m//=cur
            factors.append(cur)

    if m > 1:
        factors.append(m)
            
    print(*factors)