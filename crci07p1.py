import sys
input = sys.stdin.readline

n = int(input())

class pillar():
    def __init__(self, y, x1, x2):
        self.y = y
        self.x1 = x1
        self.x2 = x2

lis = []

for i in range(n):
    a, b, c = map(int, input().split())
    lis.append(pillar(a, b+0.5, c-0.5))

ans = 0

for i in range(n):
    pil = lis[i]
    x, y = pil.x1, pil.y
    smallest = pil.y
    for k in range(n):
        if i == k:
            continue

        if y <= lis[k].y:
            continue

        if lis[k].x1 <= x <= lis[k].x2:
            smallest = min(smallest, y-lis[k].y)

    ans += smallest
    # print(smallest)

    x, y = pil.x2, pil.y
    smallest = pil.y
    for k in range(n):
        if i == k:
            continue

        if y <= lis[k].y:
            continue

        if lis[k].x1 <= x <= lis[k].x2:
            smallest = min(smallest, y-lis[k].y)
    # print(smallest)
    ans += smallest

print(ans)