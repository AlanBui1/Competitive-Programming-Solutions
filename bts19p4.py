N, M = map(int, input().split())
v = [0] + [int(i) for i in input().split()]
v.sort()
v += [M + v[i] for i in range(1,1+N)]
psa = [0]
for i in range(1, 2*N+1):
    psa.append(psa[-1] + v[i])
ans = int(9e18)
for L in range(1, N+1):
    R = L + N - 1
    mid = (L+R)//2
    #print(L, R, (v[mid]*(mid-L))-(psa[mid-1] - psa[L-1]), (psa[R] - psa[mid]) - (v[mid] * (R - mid)))
    ans = min(ans, (v[mid]*(mid-L))-(psa[mid-1] - psa[L-1]) + (psa[R] - psa[mid]) - (v[mid] * (R - mid)))

print(ans)