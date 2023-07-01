import sys
input = sys.stdin.readline
import queue

n = int(input())
matrix = [[int(i) for i in input().split()] for k in range(n)]
graph = [[] for i in range(n)]

for i in range(n):
    for k in range(n):
        if matrix[i][k] > 0:
            graph[i].append([k, matrix[i][k]])
            
q = queue.PriorityQueue()
q.put((0, 0))

inf = int(1e9)
dist = [inf for i in range(n)]

dist[0] = 0

while not q.empty():
    curDist, curNode = q.get()
    
    for nxtNode, nxtDist in graph[curNode]:
        if dist[nxtNode] > curDist+nxtDist:
            dist[nxtNode] = curDist+nxtDist
            q.put((dist[nxtNode], nxtNode))
            
if dist[n-1] == inf:
    print(-1)
else:
    print(dist[n-1])