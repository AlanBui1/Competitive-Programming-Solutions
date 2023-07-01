def base10tobaseK(n, k):
    powers = [1]
    for i in range(40):
        if powers[-1]*k <= n:
            powers.append(powers[-1]*k)
        else:
            break

    ret = []
    leng = len(powers)
    for i in range(leng-1, -1, -1):
        if powers[i] <= n:
            ret.append(n//powers[i])
            n -= n//powers[i]*powers[i]
        else:
            ret.append(0)

    print(*ret, sep="")

def baseKtobase10(n, k):
    mult = 1
    ret = 0
    while n > 0:
        ret += mult*(n%10)
        mult *= k
        n//=10

    return ret

def solve():
    b1 = int(input())
    a = int(input())
    b2 = int(input())
    b = int(input())
    op = input()
    bf = int(input())

    A = baseKtobase10(a, b1)
    B = baseKtobase10(b, b2)

    if op == "+":
        res = A+B
    elif op == "-":
        res = A-B
    elif op == "*":
        res = A*B
    else:
        res = A//B

    base10tobaseK(res, bf)
    

t = int(input())
for _ in range(t):
    solve()
    if _ != t-1:
        input()