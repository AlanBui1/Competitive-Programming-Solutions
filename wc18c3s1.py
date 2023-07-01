import sys 
input = sys.stdin.readline

n, m, K = map(int, input().split())
pokemon = {i+1:[] for i in range(K)}

for i in range(n):
    typ, lvl = map(int, input().split())
    pokemon[typ].append(lvl)

ans = 0
if m==K:
    for i in range(K):
        ans += max(pokemon[i+1])

    print(ans)

else:
    All = []
    for i in range(K):
        high = max(pokemon[i+1])
        ans += high
        pokemon[i+1].remove(high)
        for k in pokemon[i+1]:
            All.append(k)
        
    All.sort(reverse = True)
    for i in range(m-K):
        ans += All[i]
    print(ans)