import sys
input = sys.stdin.readline

def val(a):
    return ord(a) - ord("A") + 1

a, b = map(str, input().split())

lis = []

alen = len(a)
blen = len(b)

prev = 0

p = 31
MOD = 44654641650887

for i in range(alen-1, -1, -1):
    newval = ((prev*p)%MOD + val(a[i])%MOD)%MOD
    lis.append(newval)
    prev = newval%MOD

lis.sort()
def bsearch(x):
    L = 0
    R = alen-1

    while L <= R:
        mid = (L+R)//2;
        if lis[mid] == x:
            return True
        if lis[mid] > x:
            R = mid-1
        else:
            L = mid+1

    return False

hval=0
ans = -1
curPow = 1
for i in range(min(alen, blen)):
    hval += val(b[i])*curPow
    hval %= MOD
    if bsearch(hval):
        ans = i
    
    curPow *= p
    curPow  %= MOD
    

print(a+b[ans+1:])