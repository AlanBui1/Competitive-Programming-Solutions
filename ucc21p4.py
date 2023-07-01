import sys; input = sys.stdin.readline

n = int(input())

fib = [0, 1, 1]

for i in range(3, n+1):
    fib.append((fib[i-1]+fib[i-2])%2021)

ivals = [0]+[i%50 for i in range(1, n+1)]

avals = [fib[i]+ivals[i] for i in range(n)]

import queue
q = queue.Queue()
inf = int(1e9)
dist = [inf for i in range(n+1)]
q.put(1)
dist[1] = 0;

while not q.empty():
    curNode = q.get()
    

    if curNode == n:
        break

    if curNode > 1:
        if dist[curNode-1] > dist[curNode]+1:
            dist[curNode-1] = dist[curNode]+1
            q.put(curNode-1)

    if curNode+1 <= n:
        if dist[curNode+1] > dist[curNode]+1:
            dist[curNode+1] = dist[curNode]+1
            q.put(curNode+1)

    if curNode + avals[curNode] <= n:
        if dist[curNode+avals[curNode]] > dist[curNode]+1:
            dist[curNode+avals[curNode]] = dist[curNode]+1
            q.put(curNode+avals[curNode])

    if curNode - avals[curNode] > 0:
        if dist[curNode-avals[curNode]] > dist[curNode]+1:
            dist[curNode-avals[curNode]] = dist[curNode]+1
            q.put(curNode-avals[curNode])

print(dist[n])