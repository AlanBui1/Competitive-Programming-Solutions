def gcd(a, b):
    if b == 0:
        return a
    return gcd(b, a%b)

def toStandard(X1, Y1, X2, Y2):
    A = Y1 - Y2
    B = X2 - X1
    C = -(A*X1 + B*Y1)
    G = gcd(abs(A), gcd(abs(B), abs(C)))
    if A == 0 or A < 0 or B < 0:
        A *= -1
        B *= -1
        C *= -1
    if G != 0:
        A//=G
        B//=G
        C//=G
    return[A, B, C]

def onLine(pts, X, Y, n1, n2):
    pts[0] *= n1; pts[2] *= n1
    pts[1] *= n2; pts[3] *= n2
    minX = min(pts[0], pts[2])
    maxX = max(pts[0], pts[2])
    minY = min(pts[1], pts[3])
    maxY = max(pts[1], pts[3])

    return minX <= X <= maxX and minY <= Y <= maxY 

def check(lines):
    for i in range(1, len(lines)-2, 2):
        d,e,f = toStandard(lines[i], lines[i+1], lines[i+2], lines[i+3])
        if b*d == a*e: #parallel
            if f*a == d*c:
                MIN = min(lines[i+1], lines[i+3])
                MAX = max(lines[i+1], lines[i+3])
                if y1 <= lines[i+1] <= y2 or y1 <= lines[i+3] <= y2 or MIN <= y1 <= MAX or MIN <= y2 <= MAX:
                    return 1
            pass

        else:
            x = (b*f - c*e) 
            y = (a*f - c*d)  

            if onLine(lines[i:i+4], x, y, (a*e - b*d), (b*d - a*e)) and onLine([x1,y1,x2,y2], x, y, (a*e - b*d), (b*d - a*e)):
                return 1
    return 0

x1, y1, x2, y2 = map(int, input().split())
if y1 > y2:
    y1, y2 = y2, y1
    x1, x2 = x2, x1

n = int(input())

ans = 0

a, b, c = toStandard(x1, y1, x2, y2)

if x1 == x2 and y1 == y2:
    print(0)
else:
    for i in range(n):
        lis = [int(i) for i in input().split()]
        lis.append(lis[1])
        lis.append(lis[2])
        if check(lis):
            ans += 1
    print(ans)