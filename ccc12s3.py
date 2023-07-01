import statistics 
import sys
input = sys.stdin.readline
n = int(input())
lis = {}
mode={}
for i in range(n):
  r = int(input())
  if r not in lis:
    lis[r] = 0
  lis[r]+=1

for i in lis:
  if lis[i] not in mode:
    mode[lis[i]] = []
  mode[lis[i]].append(i)
found = False
ans = 0
ans1 =0 

for i in sorted(mode.keys(), reverse=True):
  if found:
    for k in mode[i]:
      if abs(ans1-k) > ans:
        ans = abs(ans1-k)
    print(ans)
    break
  elif len(mode[i]) >= 2:
    print(max(mode[i])-min(mode[i]))
    break
  else:
    ans1 = mode[i][0]
    found = True