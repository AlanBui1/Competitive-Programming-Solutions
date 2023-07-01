import sys
input= sys.stdin.readline

n, d = map(int, input().split())

lis = [[0,0,0]]
for i in range(n):
    p, r, g = map(int, input().split())
    lis.append([p, r, g])

lis.sort()

curTime = 0

for i in range(1, n+1):
    curTime += lis[i][0] - lis[i-1][0]

    if curTime % (lis[i][1]+lis[i][2]) > lis[i][1]:
        continue

    curTime += lis[i][1]- ((curTime)%(lis[i][1]+lis[i][2]))
    
print(curTime + d-lis[-1][0])