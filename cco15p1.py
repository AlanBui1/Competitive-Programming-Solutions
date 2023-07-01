import sys
input = sys.stdin.readline
from math import inf

numcrackers, water = map(int, input().split())

lis = []

for i in range(numcrackers):
    c = int(input())
    lis.append(c)

lis.append(water)
lis.sort()
mid = lis.index(water)
lis.remove(water)

#minimum

tot = 0
tot2 = 0
tot3 = inf
tot += abs(water - lis[0])
tot2 += abs(water - lis[numcrackers -1])
if mid-1 >= 0 and mid+1 < len(lis):
    tot3 = 0
    tot3 += abs(water - lis[mid-1])
    tot3 += abs(water - lis[mid])
    for i in range(mid-2, -1, -1):
        tot3 += abs(lis[i] - lis[i+1])

    for i in range(mid+1, len(lis), 1):
        tot3 += abs(lis[i] - lis[i-1])

for i in range(1, numcrackers):
    tot += min(abs(water - lis[i]), abs(lis[i] - lis[i-1]))

for i in range(numcrackers -2, -1, -1):
    tot2 += min(abs(water - lis[i]), abs(lis[i] - lis[i+1]))



ans = str(min(tot, tot2, tot3))



#maximum
tot=0
tot2 = 0

order1 = []
order2 = []

bottom = 0
top = numcrackers -1

for i in range(numcrackers//2 ):
    if top == bottom:
        break

    else:
        order1.append(bottom)
        order1.append(top)
        order2.append(top)
        order2.append(bottom)

        top -=1
        bottom +=1

if numcrackers %2 == 1:
    order1.append(numcrackers // 2)
    order2.append(numcrackers // 2)

tot += abs(water- lis[order1[0]])
for i in range(1, len(order1)):
    tot += max(abs(lis[order1[i-1]] - lis[order1[i]]), abs(water - lis[order1[i]]))

tot2 += abs(water - lis[order2[0]])
for i in range(1, len(order2)):
    tot2 += max(abs(lis[order2[i-1]] - lis[order2[i]]), abs(water - lis[order2[i]]))

ans += " "
ans += str(max(tot, tot2)) 

print(ans)