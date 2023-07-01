n, m, k = map(int, input().split())

lis = [[0 for i in range(1005)] for k in range(1005)]

for i in range(k):
    x, y = map(int, input().split())
    lis[x][y] = 1

def num(x, y):
    return lis[x][y-1] + lis[x][y+1] + lis[x-1][y-1] + lis[x-1][y] + lis[x-1][y+1] + lis[x+1][y-1] + lis[x+1][y] + lis[x+1][y+1]

ans = 0
for i in range(1, n+1):
    for k in range(1, m+1):
       if num(i, k) >= 3 and not lis[i][k]:
           ans += 1

print(ans)