import sys
input = sys.stdin.readline

n, q = map(int, input().split())

wt = [int(k) for k in input().split()]
lis = {}
for i in wt:
  if i not in lis:
    lis[i] = 0
  lis[i]+=1

for i in range(q):
  qtype, question = map(int, input().split())
  if qtype == 1:
    if question in lis:
      if question%2 == 1: 
        if question//2 in lis:
          lis[question//2] += lis[question]
        else:
          lis[question//2] = lis[question]
        if (question//2)+1 in lis:
          lis[(question//2)+1] += lis[question]
        else:
          lis[(question//2)+1] = lis[question]
      else:        
        if question/2 in lis:
          lis[question/2] += lis[question]*2
        else:
          lis[question/2] = lis[question]*2
        
    lis[question] = 0

  else:
    if question in lis:
      print(lis[question])
    else:
      print(0)