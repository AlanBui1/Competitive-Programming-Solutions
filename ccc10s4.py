import sys
input = sys.stdin.readline
import math
from queue import PriorityQueue
from pprint import pprint as pp
n = int(input())
edges = {}
farm = [[] for i in range(n)]

for i in range(n):
    data = [int(i) for i in input().split()]
    num = data[0]
    for k in range(1, num):
        node1 = data[k]
        node2 = data[k+1]
        weight = data[k+num]
        if node1 > node2:
            tup = (node2,node1,weight)
        else:
            tup = (node1,node2,weight)
        
        if tup in edges:
            edges[tup].append(i+1)
        else:
            edges[tup] = [i+1]
    k+=1
    node1 = data[k]
    node2 = data[1]
    weight = data[-1]
    if node1 > node2:
        tup = (node2,node1,weight)
    else:
        tup = (node1,node2,weight)

    if tup in edges:
        edges[tup].append(i+1)
    else:
        edges[tup] = [i+1]
    

graphW = [[] for i in range(n+1)]
graphWO = [[] for i in range(n+1)]

for tup in edges:
    if len(edges[tup]) == 2:
        inside = True
    else:
        inside = False

    if not inside:
        graphW[edges[tup][0]].append((0, tup[2]))
        graphW[0].append((edges[tup][0], tup[2]))
    else:
        graphWO[edges[tup][0]].append((edges[tup][1], tup[2]))
        graphWO[edges[tup][1]].append((edges[tup][0], tup[2]))
        graphW[edges[tup][0]].append((edges[tup][1], tup[2]))
        graphW[edges[tup][1]].append((edges[tup][0], tup[2]))

pq = PriorityQueue()

visited = [False for i in range(n+1)]
visited[1] = True
mstCost = 0
needtoconnect = n+1
connectedsofar = 1
possible = graphW[1]
for p in possible:
    pq.put((p[1], p[0]))

while not pq.empty() and connectedsofar != needtoconnect:
    dist, curNode = pq.get()
    if visited[curNode]:
        continue
    mstCost += dist
    connectedsofar+=1
    visited[curNode] = True
    possible = graphW[curNode]
    for nxtNode, nxtDist in possible:
        if not visited[nxtNode]:
            pq.put((nxtDist, nxtNode))

pq = PriorityQueue()
visited = [False for i in range(n+1)]
visited[1] = True
mstCost2 = 0
connectedsofar = 1
needtoconnect = n
possible = graphWO[1]
for p in possible:
    pq.put((p[1], p[0]))
while not pq.empty() and connectedsofar != needtoconnect:
    dist, curNode = pq.get()
    if visited[curNode]:
        continue
    mstCost2 += dist
    connectedsofar+=1
    visited[curNode] = True
    possible = graphWO[curNode]
    for nxtNode, nxtDist in possible:
        if not visited[nxtNode]:
            pq.put((nxtDist, nxtNode))

ans = 1e9
if connectedsofar==needtoconnect:
    ans = mstCost2
print(min(ans, mstCost))