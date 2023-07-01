inf = int(1e9)

grid = [[i for i in input().split()]for k in range(10)]
ans = [[-1 for i in range(9)]for k in range(10)]

def conv(coord):
    return ord(coord[0])-65, int(coord[1])-1

def dfs(curNode, visited):
    curX = curNode[0]; curY = curNode[1]
    
    if ans[curX][curY] != -1:
        return ans[curX][curY]

    if grid[curX][curY] == -inf:
        return -inf

    if "+" not in grid[curX][curY]:
        if 65 <=ord(grid[curX][curY][0]) <= 74:
            nxt = conv(grid[curX][curY])
            if visited[nxt[0]][nxt[1]]:
                return -inf
            visited[nxt[0]][nxt[1]] = True
            toret = dfs(nxt, visited)
            visited[nxt[0]][nxt[1]] = False
            return toret
        else:
            return int(grid[curX][curY])

    ops = grid[curX][curY].split("+")
    ret = 0
    for i in ops:
        k = conv(i)
        
        if visited[k[0]][k[1]]:
            return -inf

        visited[k[0]][k[1]] = True
        ret += dfs(k, visited)
        visited[k[0]][k[1]] = False
        if ret < 0:
            return -inf
            
    ans[curX][curY] = ret
    return ret


def compute(ops):
    ret = 0

    for i in ops:
        ret += dfs(conv(i), [[False for i in range(9)]for k in range(10)])
        if ret < 0:
            return -inf
    return ret

for i in range(10):
    for k in range(9):
        if "+" not in grid[i][k]:
            if 65 <= ord(grid[i][k][0]) <= 74:
                ans[i][k] = compute([grid[i][k]])
            else:
                ans[i][k] = int(grid[i][k])
            continue

        else:
            ans[i][k] = compute(grid[i][k].split("+"))

for i in range(10):
    for k in range(9):
        if ans[i][k] <0:
            ans[i][k] = "*"

for i in range(10):
    print(*ans[i])