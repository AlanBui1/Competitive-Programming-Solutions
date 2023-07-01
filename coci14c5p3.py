n, k = map(int, input().split())
nax = int(1e5)+5

x = [0 for i in range(nax)]
y = [0 for i in range(nax)]
posints = {}
negints = {}

tim = -1
for i in range(n):
    a, b = map(int, input().split())
    if (tim != -1):
        continue

    x[a] += 1
    y[b] += 1

    if x[a] >= k or y[b] >= k:
        tim = i+1
        continue

    yint = b-a
    if yint not in posints:
        posints[yint] = 0
    posints[yint]+=1
    if posints[yint] >= k:
        tim= i+1
        continue

    yint = b+a
    if yint not in negints:
        negints[yint] = 0
    negints[yint]+=1
    if negints[yint] >= k:
        tim= i+1
        continue

print(tim)