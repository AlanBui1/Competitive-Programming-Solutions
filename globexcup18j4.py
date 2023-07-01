a,b,c,d,e,N = map(int, input().split())
MOD = int(1e9 +7)
def f(N):
    if N == 0:
        return e
    return ((a* f(N//b))%MOD + (c*f(N//d))%MOD)%MOD
print(f(N)%MOD)