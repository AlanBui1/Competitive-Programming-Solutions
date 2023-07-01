N = int(input())
chairs = [[int(i) for i in input().split()] for k in range(N)]

xs = []
ys = []

for x, y in chairs:
    xs.append(x)
    ys.append(y)

xs.sort()
ys.sort()
X = xs[N//2]
Y = ys[N//2]

ans = 0
for x, y in chairs:
    ans += abs(X - x) + abs(Y - y)
print(ans)