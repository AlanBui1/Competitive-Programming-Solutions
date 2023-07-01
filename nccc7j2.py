def gcd(a, b):
    if b == 0:
        return a
    return gcd(b, a%b)

def lcm(a, b):
    return a*b//gcd(a, b)

def solve():
    prev = 'T'
    cnt =0
    for i in range(7):
        t = input()
        if t == "J" and prev == "T":
            cnt += 1
        prev = t

    print(cnt)
    
solve()