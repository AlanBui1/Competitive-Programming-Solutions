def nasty(f1, f2):
    if abs(f1[0] - f1[1]) == sum(f2):
        return 1
    if abs(f2[0] - f2[1]) == sum(f1):
        return 1
    return 0

def solve():
    x = int(input())
    factors = []
    i = 1
    while i*i <= x:
        if x%i == 0:
            factors.append([i, x//i])
        i += 1
    
    leng = len(factors)
    for i in range(leng):
        for k in range(i+1, leng):
            if nasty(factors[i], factors[k]):
                print(x, "is nasty")
                return   

    print(x, "is not nasty")

n = int(input())
for i in range(n):
    solve()