def solve():
    vx = int(input())
    vy = int(input())
    curX = 50
    curY = 25
    
    while 0 < curX < 100 and 0 <curY < 50:
        curX += vx
        curY += vy
    
    print(curX, curY, sep=",")

for i in range(5):
    solve()