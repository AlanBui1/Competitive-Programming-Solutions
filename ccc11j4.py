lis = [[0,-1],[0,-2],[0,-3],[1,-3],[2,-3],[3,-3],[3,-4],[3,-5],[4,-5],[5,-5],[5,-4],[5,-3],[6,-3],[7,-3],[7,-4],[7,-5],[7,-6],[7,-7],[6,-7],[5,-7],[4,-7],[3,-7],[2,-7],[1,-7],[0,-7],[-1,-7],[-1,-6]]
s = [-1,-5]

direction, steps = map(str, input().split())
steps = int(steps)

while direction != 'q' and steps != 0:
  found = False
  if direction == 'l':
    for i in range(steps):
      lis.append([s[0], s[1]])
      s[0] -= 1
      if s in lis:
        found = True
         
  elif direction == 'r':
    for i in range(steps):
      lis.append([s[0], s[1]])
      s[0] += 1
      if s in lis:
        found = True

  elif direction == 'd':
    for i in range(steps):
      lis.append([s[0], s[1]])
      s[1] -= 1
      if s in lis:
        found = True
    
  elif direction == 'u':
    for i in range(steps):
      lis.append([s[0], s[1]])
      s[1] += 1
      if s in lis:
        found = True

  if not found:
    print(s[0], s[1], 'safe')
  else:
    print(s[0], s[1], 'DANGER')
    break

  direction, steps = map(str, input().split())
  steps = int(steps)