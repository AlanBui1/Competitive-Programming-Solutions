import sys
input = sys.stdin.readline
from queue import PriorityQueue

n, x= map(int, input().split())

lis = [int(i) for i in input().split()]

q = PriorityQueue()
for i in lis:
    q.put(-i)

ans = 0

for i in range(x):
    if q.empty():
        break
    val = q.get()
    ans += val
    if val+1 < 0:
        q.put(val+1)
print(-ans)