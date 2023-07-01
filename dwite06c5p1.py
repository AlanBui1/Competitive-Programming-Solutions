import sys; input = sys.stdin.readline

n = int(input())

lis = []
for i in range(n):
    x,y = map(int, input().split())
    lis.append([x, y])


for q in range(5):
    x1, y1, x2, y2 = map(int, input().split())
    ans = 0
    if x1 == x2:
        for a, b in lis:
            if a == x1:
                ans+=1

    else:
        slope = (y2-y1)/(x2-x1)
        B = y1 - (slope*x1)

        for x, y in lis:
            if y == slope*x + B:
                ans+=1

    print(ans)