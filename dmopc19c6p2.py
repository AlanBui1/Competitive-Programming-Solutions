a, b = map(int, input().split())

def factors(base, num):
    s = 0
    while num%base == 0:
        s += 1
        num //=base
    return s

def primeFactorize(n):
    freq = [0 for i in range(n+1)]
    while n > 1:
        flag = False
        if n%2 == 0:
            n//=2
            freq[2] += 1
            continue

        i = 3
        while i*i <= n:
            if n%i == 0:
                flag = True
                n//=i
                freq[i] += 1
                break
            i += 2
        
        if not flag:
            freq[n] += 1
            n //= n

    return freq

lis = primeFactorize(a)
n = 0

def f(x, n):
    s = 0
    base = x
    while x <= n:
        s += n//x
        x *= base

    return s

lim = int(1e18)
for i in range(len(lis)):
    if lis[i] > 0:
        # print(f(i, b))
        lim = min(lim, f(i, b)*lis[i])

for i in range(1, a+1):
    r = 0
    if lis[i] > 0:
        for k in range(1, b+1):  
            r += factors(i, k)

        n += r//lis[i]

print(min(n, lim))