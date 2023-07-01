n, k = map(int, input().split())
tot = [0 for i in range(n)]
worst = [-1 for i in range(n)]
for i in range(k):
    lis = [int(j) for j in input().split()]

    for j in range(n):
        tot[j] += lis[j]
        
    newlis = tot[:]
    newlis.sort(reverse = True)

    for j in range(n):
        worst[j] = max(worst[j], newlis.index(tot[j])+1)

best = max(tot)

for i in range(n):
    if tot[i] == best:
        print("Yodeller",i+1,"is the TopYodeller: score", str(best)+", worst rank",worst[i])