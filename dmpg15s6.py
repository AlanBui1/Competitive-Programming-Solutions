import queue
from decimal import *
getcontext().prec = 30
n, m = map(int, input().split())

lis = {}
cost = {}
for i in range(n):
  fruit = input()
  lis[fruit] = []
  cost[fruit] = 0

cost['APPLES'] = 1

for i in range(m):
  exchange = input().split()
  fruit1 = exchange[0]
  fruit2 = exchange[1]
  rate = Decimal(exchange[2])
  lis[fruit1].append([fruit2, rate])

q = queue.Queue()
q.put(("APPLES", Decimal(1)))
first = True
ans = 'NAW'

while not q.empty():
  curname, curcost = q.get()
  if not first:
    if curname == 'APPLES':
      if curcost > 1:
        ans = 'YA'
        break
      elif curcost <= 1:
        continue
  for nxtfruit, rate in lis[curname]:
    if curcost*rate > cost[nxtfruit]:
      cost[nxtfruit] = curcost*rate
      q.put((nxtfruit, curcost*rate))

  first = False

print(ans)