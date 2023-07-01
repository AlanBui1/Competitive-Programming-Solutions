n = int(input())
boxes = [[int(i) for i in input().split()] for k in range(n)]

for i in range(n):
    boxes[i].sort()
INF = int(1e9)+7
b = int(input())
for i in range(b):
    l, w, h = map(int, input().split())
    ans = INF
    for x, y, z in boxes:
        if x*y*z >= l*w*h:
            lis = [l, w, h]
            lis.sort()
            if lis[0] <= x and lis[1] <= y and lis[2] <= z:
                ans = min(ans, z*y*x)

    if ans == INF:
        print("Item does not fit.")
    else:
        print(ans)