import sys; input = sys.stdin.readline
C = 1
while True:
    n, m = map(int, input().split())
    if n == m == 0:
        break

    board = [["." for i in range(m)] for k in range(n)]

    qs = [int(i) for i in input().split()]
    for i in range(1, len(qs), 2):
        board[qs[i]-1][qs[i+1]-1] = "q"

    ks = [int(i) for i in input().split()]
    for i in range(1, len(ks), 2):
        board[ks[i]-1][ks[i+1]-1] = "k"

    ps = [int(i) for i in input().split()]
    for i in range(1, len(ps), 2):
        board[ps[i]-1][ps[i+1]-1] = "p"

    kmoves = [[1, -2], [1, 2], [2, 1], [-2, 1], [-1, -2],[-1, 2], [-2, -1], [2, -1]]

    safe = [[1 for i in range(m)]for k in range(n)]
    cnt = 0
    for i in range(n):
        for k in range(m):
            if board[i][k] == '.':
                continue
            if safe[i][k]:
                safe[i][k] = 0
                cnt+=1

            if board[i][k] == 'k':
                for mx, my in kmoves:
                    if 0 <= i+mx < n and 0 <= k+my < m:
                        if safe[i+mx][k+my]:
                            cnt += 1
                            safe[i+mx][k+my] = 0

            elif board[i][k] == 'q':
                x = i-1
                while x >= 0:
                    if board[x][k] != ".":
                        break
                    if safe[x][k]:
                        safe[x][k] = 0
                        cnt += 1
                    x -= 1

                y = k-1
                while y>=0:
                    if board[i][y] != ".":
                        break
                    if safe[i][y]:
                        safe[i][y] = 0
                        cnt += 1
                    y -= 1

                x = i+1
                while x < n:
                    if board[x][k] != ".":
                        break
                    if safe[x][k]:
                        safe[x][k] = 0
                        cnt += 1
                    x += 1

                y = k+1
                while y < m:
                    if board[i][y] != ".":
                        break
                    if safe[i][y]:
                        safe[i][y] = 0
                        cnt += 1
                    y += 1

                x = i-1; y = k-1

                while x >= 0 and y >= 0:

                    if board[x][y] != ".":
                        break
                    if safe[x][y]:
                        safe[x][y] = 0
                        cnt += 1

                    x -= 1
                    y -= 1

                x = i-1; y = k+1

                while x >= 0 and y < m:
                    if board[x][y] != ".":
                        break
                    if safe[x][y]:
                        safe[x][y] = 0
                        cnt += 1

                    x -= 1
                    y += 1

                x = i+1; y = k-1
                while x < n and y >= 0:
                    if board[x][y] != ".":
                        break
                    if safe[x][y]:
                        safe[x][y] = 0
                        cnt += 1

                    x += 1
                    y -= 1

                x = i+1; y = k+1

                while x < n and y < m:
                    if board[x][y] != ".":
                        break
                    if safe[x][y]:
                        safe[x][y] = 0
                        cnt += 1

                    x += 1
                    y += 1

                

    print("Board", C, "has", n*m-cnt, "safe squares.")
    C+=1