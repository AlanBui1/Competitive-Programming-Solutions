import sys; input = sys.stdin.readline
import queue

n, m = map(int, input().split())

graph = [[] for i in range(n)]

for i in range(m):
    a, b, d = map(int, input().split())
    graph[a-1].append([b-1, d])
    graph[b-1].append([a-1, d])
inf = int(1e9)
dist = [[inf, inf] for i in range(n)]

dist[0] = [0,0] #danger, dist

q = queue.Queue()
q.put((0, 0, 0))

while not q.empty():
    curNode, curDist, curDanger = q.get()
    
    if dist[curNode][0] < curDanger:
        continue
    if dist[curNode][0] == curDanger and dist[curNode][1] < curDist:
        continue

    for nxtNode, nxtDist in graph[curNode]:
        if dist[nxtNode][0] > curDanger+nxtDist:
            dist[nxtNode][0] = curDanger+nxtDist
            dist[nxtNode][1] = curDist+1
            q.put((nxtNode, dist[nxtNode][1], dist[nxtNode][0]))

        elif dist[nxtNode][0] == curDanger+nxtDist and dist[nxtNode][1] > curDist+1:
            dist[nxtNode][1] = curDist+1
            q.put((nxtNode, dist[nxtNode][1], dist[nxtNode][0]))


if dist[n-1] == [inf, inf]:
    print(-1)
else:
    print(*dist[n-1])