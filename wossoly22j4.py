import sys
input = sys.stdin.readline
INF = int(1e9)
n, m= map(int, input().split())
lis = []
diff = [0 for i in range(n+2)]

closestDist = [INF for i in range(n+2)]
closest = [INF for i in range(n+2)]
left = [INF for i in range(n+2)]
left[1] = 1
left[n] = n
right = [INF for i in range(n+2)]
right[1] = 1
right[n] = n

import queue
q = queue.Queue()
q.put((1, 1, n, 1, 0)) #a, left, right, cur, curDist
q.put((n, 1, n, n, 0))

for i in range(m):
    a, b = map(int, input().split())
    q.put((a, max(1, a-b), min(n, a+b), a, 0))
    diff[max(1, a-b)] += 1
    diff[min(n+1, a+b+1)] -= 1
    left[a] = max(1, a - b)
    right[a] = min(a + b, n)

while not q.empty():
    a, L, R, cur, curDist = q.get()
    if not (L <= cur <= R):
        continue
    if not((closest[cur] < a and curDist >= closestDist[cur]) or (curDist > closestDist[cur])):
        closestDist[cur] = curDist
        closest[cur] = a
    else:
        if cur < a:
            cur = left[closest[cur]]
        else:
            cur= right[closest[cur]]
        curDist = abs(a - cur)

    if cur == a:
        q.put((a, L, R, cur-1, curDist+1))
        q.put((a, L, R, cur+1, curDist+1))
    elif cur < a:
        q.put((a, L, R, cur-1, curDist+1))
    else:
        q.put((a, L, R, cur+1, curDist+1))
        
for i in range(1, n+2):
    diff[i] += diff[i-1]

q = int(input())

for _ in range(q):
    op, x = map(int, input().split())

    if op == 1:
        print(closest[x])
    else:
        print(diff[x] + 1)