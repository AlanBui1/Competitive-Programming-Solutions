lis = {'A':0, 'B':1, 'C':2, 'D':3, 'E':4, 'F':5, 'G':6, 'H':7, 'I':8, 'J':9, 'K':10, 'L':11, 'M':12, 'N':13, 'O':14, 'P':15, 'Q':16, 'R':17, 'S':8, 'T':19, 'U':20,'V':21, 'W':22, 'X':23, 'Y':24, 'Z':25}
ans = 0
g = [[] for i in range(26)]
x = 0
re = []
while True:
  road = input()
  re.append(road)
  if road == '**':
    break
  g[lis[road[0]]].append(lis[road[1]])
  g[lis[road[1]]].append(lis[road[0]])
  x += 1

def dfs(node):
  global found
  visited[node] = True
  if node == 1:
    found = True
    return
  for nxt in g[node]:
    if not visited[nxt]:
      dfs(nxt)

for i in range(x):
  found = False
  visited = [False for i in range(26)]
  g[lis[re[i][0]]].remove(lis[re[i][1]])
  g[lis[re[i][1]]].remove(lis[re[i][0]])
  dfs(0)
  g[lis[re[i][0]]].append(lis[re[i][1]])
  g[lis[re[i][1]]].append(lis[re[i][0]])
  if found:
    continue
  ans += 1
  print(re[i])

print('There are',ans,'disconnecting roads.')