import sys
input = sys.stdin.readline

n, d = map(int, input().split())
arr = [int(i) for i in input().split()]
psa = [0]
for i in range(n):
    psa.append(psa[-1]+arr[i])

l, r = 1, n

for i in range(d):
    x = int(input())
    x += l-1
    #print(l, r)

    if psa[x] - psa[l-1] >= psa[r] - psa[x]:
        print(psa[x] - psa[l-1])
        l = x+1
        
    else:
        print(psa[r] - psa[x])
        r = x