from collections import deque

n, k = map(int, input().split())
num = [int(i) for i in input()]

dq = deque()

for i in range(n):
    if not k:
        break
    while dq and dq[0][0] < num[i] and k:
        k -= 1
        x = dq.popleft()
        num[x[1]] = ""
    dq.appendleft((num[i], i))

print(*num, sep="")