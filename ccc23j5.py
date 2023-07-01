ans = 0

def wordSearch(x, y, vx, vy, curInd, hasRotated):
    global ans
    # print(x, y, curInd)
    #return True if we can find the word we want starting from this point

    #BASE CASE
    if curInd == len(want):
        ans += 1
        # print(x, y)
        return

    if 0 <= x+vx < rows and 0 <= y+vy < cols:
        if grid[x+vx][y+vy] == want[curInd]:
            wordSearch(x+vx, y+vy, vx, vy, curInd+1, hasRotated)

    if not hasRotated and curInd > 1:
        if vx == 0:
            wordSearch(x, y, -1,0, curInd, True)
            wordSearch(x, y, 1, 0, curInd, True)
        elif vy == 0:
            wordSearch(x, y, 0, -1, curInd, True)
            wordSearch(x, y, 0, 1, curInd, True)
        elif (vx == 1 and vy == -1) or (vx == -1 and vy == 1):
            wordSearch(x, y, -1, -1, curInd, True)
            wordSearch(x, y, 1, 1, curInd, True)
        else:
            wordSearch(x, y, 1, -1, curInd, True)
            wordSearch(x, y, -1, 1, curInd, True)
want = input()
rows = int(input())
cols = int(input())

grid = [[i for i in input().split()] for k in range(rows)]

for r in range(rows):
    for c in range(cols):
        if grid[r][c] == want[0]:
            for VX in [-1, 0, 1]:
                for VY in [-1, 0, 1]:
                    if VX == 0 and VY == 0:
                        continue
                    wordSearch(r, c, VX, VY, 1, False)

print(ans)