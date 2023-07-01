n = int(input())

def factorize(n):
    x = []
    i = 1
    while i*i <= n:
        if n%i == 0:
            x.append(i)
            if i != n//i and i != 1:
                x.append(n//i)

        i += 1

    return x

love = 0

def works(x, s, l):
    seq = s[:x]
    for i in range(0, l, x):
        if s[i:i+x] != seq:
            return 0

    return 1

for i in range(n):
    lis = input().split()
    leng = int(lis[0])
    string = lis[1]

    factors = factorize(leng)
    val = 0

    for f in factors:
        if love < f/(leng/f):
            if works(f, string, leng):
                love = max(love, f/(leng/f))
    love = max(love, val)

print(love)