n= int(input())
grid = [[i for i in input()] for k in range(n)]

cnt = [0 for i in range(n)]

for i in range(n):
    for k in range(n):
        if grid[i][k] == "S":
            cnt[k] += 1
            
ans = [["." for i in range(n)]for k in range(n)]

for i in range(n):
    for k in range(n-1, n-1-cnt[i], -1):
        ans[i][k] = "S"

ans2 = [["." for i in range(n)]for k in range(n)]
for i in range(n):
    for k in range(n):
        ans2[i][k] = ans[k][i]
        
for i in range(n):
    print(*ans2[i], sep="")