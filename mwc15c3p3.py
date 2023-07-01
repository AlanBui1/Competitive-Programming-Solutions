n, q= map(int, input().split())

grid = [input().split() for i in range(n)]

moves = [[0,1], [1,0], [1,1], [1,-1], [0,-1], [-1,0],[-1,-1], [-1, 1]]
used = [[0 for i in range(n)] for k in range(n)]

def found(cur, limit, x, y, want, has, n):
    if cur == limit:
        return has == want

    if x < 0 or x >= n or y >= n or y < 0:
        return 0

    ret = 0

    for mx, my in moves:
        if ret:
            return ret
        x += mx
        y += my

        if 0 <= x < n and 0 <= y < n:
            if not used[x][y] and grid[x][y] == want[cur]:
                used[x][y] = 1
                ret |= found(cur+1, limit, x, y, want, has+grid[x][y], n)
                used[x][y] = 0

        x -= mx
        y -= my
        
    return ret

def solve(word, n):
    leng = len(word)
    for i in range(n):
        for k in range(n):
            used[i][k] = 1
            if found(1, leng, i, k, word, grid[i][k], n):
                return True
            used[i][k] = 0
    return False



for _ in range(q):
    word = input()
    if solve(word, n):
        print("good puzzle!")
    else:
        print("bad puzzle!")