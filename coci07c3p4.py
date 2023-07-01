import sys
input=sys.stdin.readline

n = int(input())

xs = dict()
ys = dict()
lis = []
for _ in range(n):
    x, y = map(int, input().split())
    if x not in xs:
        xs[x] = 0
    if y not in ys:
        ys[y] =0
    xs[x]+=1
    ys[y]+=1
    lis.append([x,y])

ans = 0

for x,y in lis:
    ans += (xs[x]-1)*(ys[y]-1)

print(ans)