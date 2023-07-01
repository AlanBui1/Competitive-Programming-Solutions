import sys; input = sys.stdin.readline

n = int(input())
graph = [[] for i in range(n)]

for i in range(n-1):
    a = int(input())
    graph[a-1].append(i)

lis = {0}

def dfs(curNode, mask):
    for k in range(n-1):
        if mask & (1<<k):
            for i in graph[k]:
                mask |= 1<<i
                
    for k in range(n-1):
        if mask & (1<<k):
            for i in graph[k]:
                mask |= 1<<i

    lis.add(mask)

    for i in range(n-1):
        if not mask & (1 << i):
            dfs(i, mask ^ (1<<i))

for i in range(n-1):
    start = 0
    start |= (1<<i)
    dfs(i, start)

print(len(lis))