import copy
import sys
input = sys.stdin.readline
n = int(input())
lis = []
for i in range(n):
  profit, energy, prep = map(int, input().split())
  lis.append((profit,energy,prep))

tot = int(input())
new = []
for oriprof, energyloss, oriprep in lis:
  prep = oriprep
  prof = oriprof
  new.append([1, prof, prep])

  for i in range(2, (tot//prep)+2):
    prof += oriprof - (energyloss*(i-1))
    prep = oriprep*i
    if prof <= 0 or prep > tot:
      break
    new.append([i, prof, prep])
  
arr = [[0, 0] for i in range(tot+1)]

used = {}
nxt = copy.deepcopy(arr)

for k in range(0, len(new)):
  cur = new[k][0]
  prof = new[k][1]
  prep = new[k][2]
  if cur in used:
    used = {}
    arr = copy.deepcopy(nxt)
  used[cur] = True
  for j in range(tot, -1, -1):
    maxWO = nxt[j][1]
    maxW = 0
    if j >= prep:   
      maxW += prof+arr[j-prep][1]

    if maxW > maxWO:
      nxt[j][1] = maxW
      nxt[j][0] = arr[j-prep][0]+cur

    elif maxW == maxWO:
      nxt[j][0] = min(nxt[j][0], arr[j-prep][0]+cur)
print(nxt[tot][1])
print(nxt[tot][0])