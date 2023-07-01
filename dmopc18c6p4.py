import sys; input = sys.stdin.readline

n, p, m = map(int, input().split())

def bsearch(inp, val, L, R):
    ret = -1
    while L <= R:
        mid = (L+R)//2

        if inp[mid] <= val:
            ret = max(ret, mid)
            L = mid+1

        else:
            R = mid-1

    return ret

lis = [[int(i) for i in input().split()]for k in range(n)]

phys = [int(i) for i in input().split()]
magic = [int(i) for i in input().split()]

phys.sort()
magic.sort()

psa1 = [phys[0]]
psa2 = [magic[0]]

for i in range(1,m):
    psa2.append(psa2[-1]+magic[i])

for i in range(1,p):
    psa1.append(psa1[-1]+phys[i])

ans = int(1e18)
ansind = -1
cnt=1
for deff, res in lis:
    ind1 = bsearch(phys, deff, 0, p-1)
    ind2 = bsearch(magic, res, 0, m-1)

    dmg1 = psa1[-1]
    dmg2 = psa2[-1]

    if ind1 != -1:
        dmg1 -= psa1[ind1]
    
    if ind2 != -1:
        dmg2 -= psa2[ind2]
    ind1 += 1
    ind2 += 1

    dmg1 -= (p-ind1)*deff
    dmg2 -= (m-ind2)*res

    if dmg1+dmg2 < ans:
        ans = dmg1+dmg2
        ansind = cnt
    cnt+=1

print(ansind)