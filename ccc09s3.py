import queue

lis = [[5], [5], [3,4,5,14], [2,4,5], [2,3,5], [0,1,2,3,4,6], [5,7], [6,8], [7,9,11], [8,10], [9,11], [8,10,12], [11,13,14], [12], [2,12], [16,17], [15,17], [15,16], [], [], [], [], [], [], [], [], [], [], [], [], [], [], [], [], [], [], [], [], [], [], [], [], [], [], [], [], [], [], [], []]

x = input()
while x != 'q':
  if x == 'i':
    p1 = int(input())
    p2 = int(input())
    if p2-1 not in lis[p1-1]:
      lis[p1-1].append(p2-1)
      lis[p2-1].append(p1-1)
  elif x == 'd':
    p1 = int(input())
    p2 = int(input())
    lis[p1-1].remove(p2-1)
    lis[p2-1].remove(p1-1)
  elif x == 'n':
    p1 = int(input())
    print(len(lis[p1-1]))
  elif x == 'f':
    p1 = int(input())
    frs = []
    for i in (lis[p1-1]):
      for node in lis[i]:
        if node not in frs and node not in lis[p1-1]:
          frs.append(node)
    print(len(frs)-1)
  elif x == 's':
    p1 = int(input())
    p2 = int(input())
    q = queue.Queue()
    q.put([p1-1, 0])
    visited = [False for i in range(50)]
    ans = 'Not connected'
    while not q.empty():
      node, dist = q.get()
      if node == p2-1:
        ans = dist
        break
      if not visited[node]:
        visited[node] = True
        for nxt in lis[node]:
          q.put([nxt, dist+1])
    print(ans)
  x = input()