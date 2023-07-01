a, b, c = map(int, input().split())
x, y, z = map(int, input().split())

def gcd(a, b):
    if b == 0:
        return a
    return gcd(b, a%b)

G = gcd(x, gcd(y, z))
x //= G
y //=G
z //=G

times = int(1e9)
times = min(a//x, b//y, c//z)

a -= times*x
b -= times*y
c -= times*z

if a == 0 or b == 0 or c == 0:
    print(a, b, c)
else:
    if min(a/x, b/y, c/z) == a/x:
        print(0, b-(y*a/x), c-(z*a/x))
    elif min(a/x, b/y, c/z) == b/y:
        print(a-(x*b/y), 0, c-(z*b/y))
    else:
        print(a-(x*c/z), b-(y*c/z), 0)