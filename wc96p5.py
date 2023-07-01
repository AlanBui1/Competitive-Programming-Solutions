import math

m, n = map(int, input().split())
graph = [[0 for i in range(n)]for k in range(m)]

a, b = map(int, input().split())

while a != 0 or b != 0:
  graph[a-1][b-1] = 1

  a, b = map(int, input().split())

for i in range(m):
  for k in range(n):
    if i == 0 and k == 0:
      continue
    left = -math.inf
    down = -math.inf
    if i > 0:
      down = graph[i-1][k]+graph[i][k]

    if k > 0:
      left = graph[i][k-1]+graph[i][k]

    graph[i][k] = max(left, down)

print(graph[i][k])