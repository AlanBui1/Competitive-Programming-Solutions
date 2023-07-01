import sys
input = sys.stdin.readline

n, m = map(int, input().split())

class car:
    def __init__(self, a, b):
        self.a = a
        self.b = b
        self.d = b-a
        self.t = (b-a)*2

lis = []

for i in range(n):
    A, B = map(int, input().split())
    newcar = car(A, B)
    lis.append(newcar)

for _ in range(m):
    x, y, t = map(int, input().split())
    
    ans = 0

    for i in range(n):
        dist = t%lis[i].t
        if dist > lis[i].d:
            dist = lis[i].b - dist + lis[i].d
        else:
            dist+= lis[i].a
        # print(dist)
        if x <= dist <= y:
            # print(i, dist)
            ans += 1

    print(ans)

# 5 1
# 0 1
# 0 2
# 2 3
# 3 5
# 4 5
# 2 5 3