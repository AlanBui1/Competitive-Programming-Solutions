import math
from queue import PriorityQueue
for i in range(5):
  n = int(input())
  lis = {'YYZ':0, 'SEA':1}
  lis2 = ['YYZ', 'SEA']
  cost = []
  flight = []
  for k in range(n):
    node1, node2, weight = map(str, input().split())
    if node1 not in lis2:
      lis[node1] = len(lis)
      lis2.append(node1)
    if node2 not in lis2:
      lis[node2] = len(lis)
      lis2.append(node2)
    cost.append(int(weight))
    flight.append([node1, node2])
  g = [[] for j in range(len(lis))]
  for b in range(n):
    g[lis[flight[b][0]]].append([lis[flight[b][1]], cost[b]])
  q = PriorityQueue()
  start = 0
  q.put((0,start))
  dist = [math.inf for h in range(len(lis))]
  dist[start] = 0
  while not q.empty():
    cur = q.get()
    node = cur[1]
    possible = g[node]
    for p in possible:
      w = p[1]
      x = p[0]
      if dist[node]+w < dist[x]:
        dist[x] = dist[node]+w
        q.put((dist[x],x))
  print(dist[1])