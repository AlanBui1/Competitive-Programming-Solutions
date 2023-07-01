r, c = map(int, input().split())
grid = [[str(i) for i in input()]for k in range(r)]
new = [[str(i) for i in grid[k]] for k in range(r)]
mask = [[grid[k][i] == "." for i in range(c)]for k in range(r)]

for i in range(r):
    for k in range(c):
        cnt = 0
        if i > 0:
            cnt += (grid[i-1][k] == ".")
        else:
            cnt+=1
        if i < r-1:
            cnt += (grid[i+1][k] == ".")
        else:
            cnt+=1
            
        if k > 0:
            cnt += (grid[i][k-1] == ".")
        else:
            cnt+=1
        if k < c-1:
            cnt += (grid[i][k+1] == ".")
        else:
            cnt+=1

        if cnt >= 3:
            new[i][k] = "."

left = c
right = -1
top = r
bottom = -1

for i in range(r):
    for k in range(c):
        if new[i][k] == "X":
            top = min(top, i)
            bottom = max(bottom, i)
            right = max(right, k)
            left = min(left, k)

for i in range(top, bottom+1):
    print(*new[i][left:right+1],sep="")