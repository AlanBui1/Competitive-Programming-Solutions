n = int(input())
a= [int(i) for i in input().split()]
MOD = int(1e9)+7

def power(x, n):
    mult = x
    ret = 1
    while n > 0:
        if n & 1:
            ret *= mult 
            ret %= MOD
        mult *= mult
        n//=2

    return ret

print(sum(a)*power(2, n-1)%MOD)