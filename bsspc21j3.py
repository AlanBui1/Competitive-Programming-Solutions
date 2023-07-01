m, n = map(int, input().split())

grid = [[i for i in input()] for k in range(n)]

red = [[0 for i in range(m)] for k in range(n)]
blue = [[0 for i in range(m)] for k in range(n)]
yellow = [[0 for i in range(m)] for k in range(n)]

for i in range(n):
    for k in range(m):
        if grid[i][k] == "R":
            red[i][k] += 1
        elif grid[i][k] == "U":
            blue[i][k] += 1
        elif grid[i][k] == "Y":
            yellow[i][k]  += 1
        elif grid[i][k] == "O":
            red[i][k] += 1
            yellow[i][k] += 1
        elif grid[i][k] == "G":
            yellow[i][k] += 1
            blue[i][k] += 1
        elif grid[i][k] == "P":
            blue[i][k] += 1
            red[i][k] += 1
        elif grid[i][k] != ".":
            blue[i][k] += 1
            red[i][k] += 1
            yellow[i][k] += 1    

redUsed = 0
blueUsed = 0
yellowUsed = 0

for i in range(n):
    painting = False
    for k in range(m):
        if red[i][k] and not painting:
            redUsed += 1
            painting = True
        if not red[i][k]:
            painting = False


for i in range(n):
    painting = False
    for k in range(m):
        if yellow[i][k] and not painting:
            yellowUsed += 1
            painting = True
        if not yellow[i][k]:
            painting = False


for i in range(n):
    painting = False
    for k in range(m):
        if blue[i][k] and not painting:
            blueUsed += 1
            painting = True
        if not blue[i][k]:
            painting = False

print(redUsed, yellowUsed, blueUsed)