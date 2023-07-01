import sys;
input =sys.stdin.readline

graph = [[] for i in range(10)]
graph2 = [[] for i in range(10)]

graph[1].append(7)
graph[1].append(4)
graph[2].append(1)
graph[3].append(4)
graph[3].append(5)

graph2[7].append(1)
graph2[4].append(1)
graph2[1].append(2)
graph2[4].append(3)
graph2[5].append(3)

while True:
    n = int(input())
    m = int(input())
    if n == 0 == m:
        break

    graph[n].append(m)
    graph2[m].append(n)

for i in range(8):
    graph2[i].sort()

flag = False
visited = [False for i in range(10)]

def hasCycle(curNode):
    visited[curNode] = True
    ret = False
    for nxt in graph[curNode]:
        if visited[nxt]:
            return True
        ret |= hasCycle(nxt)
    visited[curNode] = False
    return ret

def topsort(curNode):
    visited[curNode] = True
    
    for i in graph[curNode]:
        if not visited[i]:
            topsort(i)

    order.append(curNode)

for i in range(7, 0, -1):
    visited = [False for i in range(10)]
    if hasCycle(i):
        flag = True
        break

if flag:
    print("Cannot complete these tasks. Going to bed.")

else:
    order = []
    visited = [False for i in range(10)]
    for i in range(7, 0, -1):
        if not visited[i]:
            topsort(i)
    
    print(*reversed(order))