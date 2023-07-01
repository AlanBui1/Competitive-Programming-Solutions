def gcd(a, b):
    if b == 0:
        return a
    return gcd(b, a%b)

n = int(input())

grid = [[i for i in input()]for k in range(n)]
lis = []

for i in range(n):
    for k in range(n):
        if grid[i][k] != ".":
            lis.append([i, k])

leng = len(lis)
ans = 0
for i in range(leng):
    for j in range(i+1, leng):
        for k in range(j+1, leng):

            x1, y1 = lis[i]
            x2, y2 = lis[j]
            x3, y3 = lis[k]

            pts = [lis[i], lis[j], lis[k]]
            pts.sort()

            #print(pts)

            deltay = pts[1][0] - pts[0][0]
            deltax = pts[1][1] - pts[0][1]

            G = gcd(abs(deltax), abs(deltay))

            dy = pts[2][0] - pts[1][0]
            dx = pts[2][1] - pts[1][1]

            g = gcd(abs(dy), abs(dx))
            
            if deltay//G == dy//g and deltax//G == dx//g:
                ans += 1
                

print(ans)