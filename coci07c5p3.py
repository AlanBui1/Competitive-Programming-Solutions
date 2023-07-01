import sys
input =sys.stdin.readline

x1, y1 = map(int, input().split())
x2, y2 = map(int, input().split())
x3, y3 = map(int, input().split())

lis = [[x1, y1], [x2, y2], [x3, y3]]

def area(pts):
    xa, ya = pts[0]
    xb, yb = pts[1]
    xc, yc = pts[2]
    
    return abs((xa*(yb-yc)) + (xb*(yc-ya)) + (xc*(ya-yb)))/2

orig = area(lis)
print("%.1f" %orig)

n= int(input())

ans = 0
for _ in range(n):
    x, y =map(int, input().split())
    if orig == area([[x1, y1], [x2, y2], [x, y]]) + area([[x1, y1], [x, y], [x3, y3]]) + area([[x, y], [x2, y2], [x3, y3]]):
        ans += 1
print(ans)