motels = [0, 990, 1010, 1970, 2030, 2940, 3060, 3930, 4060, 4970, 5030, 5990, 6010, 7000]
a = int(input())
b = int(input())
n = int(input())
for i in range(n):
    newMotel = int(input())
    motels.append(newMotel)

motels.sort()

graph = [[] for i in range(len(motels))]
for i in range(len(motels)):
    cur = motels[i]
    for k in range(i+1, len(motels)):
        if cur+a <= motels[k] <= cur+b:
            graph[i].append(k)

        elif cur+b < motels[k]:
            break


dist = [-1 for i in range(len(motels)+1)]
def dfs(curNode):
    if dist[curNode] != -1:
        return dist[curNode]

    if curNode == len(motels)-1:
        return 1
    else:
        ret = 0

        possible = graph[curNode]
        for p in possible:
            ret += dfs(p)

    dist[curNode] = ret;
    return ret

print(dfs(0))