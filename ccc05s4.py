def lca(x, y):
    left = first[x]
    right = first[y]
    if left > right:
        temp = left
        left = right
        right = left
    
    searchLis = lis[left : right+1]
    smallest = int(1e9)
    bestName = ""

    for name in searchLis:
        if smallest > heights[name]:
            smallest = heights[name]
            bestName = name
    return bestName
    
def dist(x, y):
    return heights[x] + heights[y] - (2* heights[lca(x, y)])
    
T = int(input())
for _ in range(T):
    n = int(input())
    lis = [input() for i in range(n)]

    heights = {}
    visited = {}
    first = {lis[-1]: 0}

    visited[lis[-1]] = 1
    heights[lis[-1]] = 0
    curHeight = 0
    cnt = 1
    for name in lis:
        if name in visited:
            curHeight -= 1
        else:
            curHeight += 1
            first[name] = cnt
        visited[name] = 1
        heights[name] = curHeight
        cnt +=1 

    oldTime = n*10

    lis = [lis[-1]] + lis
    
    newTime = 0
    for name in lis:
        newTime = max(newTime, dist(lis[-1], name))

    newTime *= 20

    print(oldTime - newTime)