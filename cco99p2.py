n = int(input())
translate = {'0':'0th', '1':'1st', '2':'2nd', '3':'3rd', '4':'4th', '5':'5th', '6':'6th', '7':'7th', '8':'8th', '9':'9th', '10':'10th', '11':'11th', '12':'12th', '13':'13th'}

def tr(word, left):
  global found

  if left in translate:
    found = True
    print(word+translate[left], 'most common word(s):')
    return 
  
  for x in range(len(left)):
    if found:
      return
    tr(word+left[x], left[x+1:])

for q in range(n):
  found = False
  m, k = map(int, input().split())
  lis = []
  rank = []
  end = len(str(k))
  tr('', str(k))

  if m == 0:
    continue
  
  for i in range(m):
    word = input()
    if word not in lis:
      lis.append(word)
      rank.append([1, word])
    else:
      rank[lis.index(word)][0] += 1

  if k> m:
    continue

  rank.sort(reverse = True)
  val = [[] for i in range(len(rank))]
  x = 0
  val[x].append(rank[0][1])

  for i in range(1, len(rank)):
    if rank[i][0] != rank[i-1][0]:
      x+=1
    val[x].append(rank[i][1])

  k = int(k)
  tot = 0
  x=0
  while tot < k-1:
    tot += len(val[x])
    x+=1

  if tot == k-1:
    for i in val[x]:
      print(i)