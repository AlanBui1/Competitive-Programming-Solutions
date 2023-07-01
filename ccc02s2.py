def gcd(a, b):
    if b == 0:
        return a
    return gcd(b, a%b)

def lcm(a, b):
    return a/lcm(a,b)*b

n = int(input())
m = int(input())

if n == 0:
    print(0)

else:
    GCD = gcd(n, m)
    n //= GCD
    m //= GCD

    whole = 0

    while n > m:
        whole += 1
        n -= m

    if n / m == 1:
        whole += 1
        print(whole)

    elif whole == 0:
        print(str(n)+"/"+str(m))
    else:
        print(whole, str(n)+"/"+str(m))