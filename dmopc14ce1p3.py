n = int(input())
m = int(input())
g = [[] for i in range(n)] 
re = []
for i in range(m):
  a, b = map(int, input().split())
  g[a-1].append(b-1)
  g[b-1].append(a-1)
  re.append([a-1, b-1])
element = {}
found = False
c = 0
h = 0
p = 0
for i in range(n):
  if len(g[i]) == 1:
    element[i] = 'H'
    p = i
    h += 1
  elif len(g[i]) == 4:
    element[i] = 'C'
    c += 1
  else:
    print('Impossible')
    found = True
    break

ans = 0
bond = []
if not found:
  for i in range(m):
    if element[re[i][0]] == 'H':
      if element[re[i][1]] == 'C':
        ans += 413
    elif element[re[i][0]] == 'C':
      if element[re[i][1]] == 'C':
        if re[i] in bond:
          ans += 269
        elif reversed(re[i]) in bond:
          ans += 269
        else:
          ans += 346
        bond.append(re[i])
      elif element[re[i][1]] == 'H':
        ans += 413
  print(ans)
  if c == 1:
    print('CH'+str(h))
  else:
    print('C'+str(c)+'H'+str(h))