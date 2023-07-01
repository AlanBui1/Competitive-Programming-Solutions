moves = [[0, -1], [1, 0], [0, 1], [-1, 0]]
mx, my = moves[1]
cur = 1
def rotate():
    global cur, mx, my
    cur = (cur+1)%4
    mx, my = moves[cur]

minX, minY, maxX, maxY = 150,150,150,150

grid = [[" " for i in range(300)] for k in range(300)]
x = int(input())
y = int(input())

curX = curY = 150
grid[curX][curY] = x

count = 0
left = 1
curr = 1
for i in range(x+1, y+1):
    # print(i,cur, curr, left, count)
    if left == 0:
        rotate()
        count += 1
        if count %2 == 0:
            curr += 1
        left = curr 
    
    left -= 1
    curX += mx
    curY += my
    grid[curX][curY] = i

    minX = min(minX, curX)
    maxX = max(maxX, curX)
    minY = min(minY, curY)
    maxY = max(maxY, curY)
    

for i in range(minX, maxX+1):
    print(*grid[i][minY : maxY+1])