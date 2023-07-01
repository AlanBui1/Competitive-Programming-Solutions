r, c = map(int, input().split())

grid = [[i for i in input()] for k in range(r)]

word = "z"*25

for i in range(r):
    for k in range(c):
        if grid[i][k] == "#":
            continue

        if k == 0:
            x = k
            cur = ""
            while x < c:
                if grid[i][x] == "#":
                    break
                cur += grid[i][x]
                x += 1
            if cur < word and len(cur)>2:
                word = cur

        else:
            if grid[i][k-1] == "#":
                x = k
                cur = ""
                while x < c:
                    if grid[i][x] == "#":
                        break
                    cur += grid[i][x]
                    x += 1
                if cur < word and len(cur)>2:
                    word = cur
        cur = ""
        if i == 0:
            y = i
            while y < r:
                if grid[y][k] == "#":
                    break
                cur += grid[y][k]
                y += 1
            if cur < word and len(cur) > 1:
                word = cur
        else:
            if grid[i-1][k] == "#":
                y = i
                while y < r:
                    if grid[y][k] == "#":
                        break
                    cur += grid[y][k]
                    y += 1
                if cur < word and len(cur) > 1:
                    word = cur

print(word)