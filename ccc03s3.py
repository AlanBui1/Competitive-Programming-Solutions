wood = int(input())

r = int(input())
c = int(input())

grid = [[i for i in input()]for k in range(r)]

visited = [[(grid[k][i] == "I")for i in range(c)]for k in range(r)]

rooms = 0
lis = []

def dfs(curX, curY):
    global r, c, s
    visited[curX][curY] = True
    s+=1

    if curX-1 >= 0:
        if not visited[curX-1][curY]:
            dfs(curX-1, curY)

    if curX+1 < r:
        if not visited[curX+1][curY]:
            dfs(curX+1, curY)

    if curY-1 >= 0:
        if not visited[curX][curY-1]:
            dfs(curX, curY-1)

    if curY+1 < c:
        if not visited[curX][curY+1]:
            dfs(curX, curY+1)


for i in range(r):
    for k in range(c):
        s =0
        if not visited[i][k]:
            rooms+=1
            dfs(i, k)
            lis.append(s)
lis.sort(reverse=True)
cnt =0 
for i in range(rooms):
    if wood - lis[i] >= 0:
        cnt+=1
        wood -= lis[i]
    else:
        break

if cnt == 1:
    print("1 room,",wood, "square metre(s) left over")
else:
    print(cnt,"rooms,",wood, "square metre(s) left over")