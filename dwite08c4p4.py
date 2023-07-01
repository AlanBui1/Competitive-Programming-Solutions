import queue

for _ in range(5):

    grid = [[k for k in input()]for j in range(8)]
    visited = [[False for i in range(8)]for k in range(8)]

    for i in range(8):
        for k in range(8):
            if grid[i][k] == "A":
                start = [i, k]
                visited[i][k] = True

            elif grid[i][k] == "B":
                end = [i, k]
            
            elif grid[i][k] == "#":
                visited[i][k] = True

    
    q = queue.Queue()
    q.put((start, 0))
    
    while not q.empty():
        cur, curDist = q.get()
        
        if cur == end:
            print(curDist)
            break
    
        if cur[0]+1 < 8:
            if not visited[cur[0]+1][cur[1]]:
                visited[cur[0]+1][cur[1]] = True
                q.put(([cur[0]+1, cur[1]], curDist+1))

        if cur[1]+1 < 8:
            if not visited[cur[0]][cur[1]+1]:
                visited[cur[0]][cur[1]+1] = True
                q.put(([cur[0], cur[1]+1], curDist+1))
            
        if cur[1]+1 < 8 and cur[0]+1 < 8:
            if not visited[cur[0]+1][cur[1]+1]:
                visited[cur[0]+1][cur[1]+1] = True
                q.put(([cur[0]+1, cur[1]+1], curDist+1))

        if cur[0]-1 >=0:
            if not visited[cur[0]-1][cur[1]]:
                visited[cur[0]-1][cur[1]] = True
                q.put(([cur[0]-1, cur[1]], curDist+1))

        if cur[1]-1 >=0:
            if not visited[cur[0]][cur[1]-1]:
                visited[cur[0]][cur[1]-1] = True
                q.put(([cur[0], cur[1]-1], curDist+1))
            
        if cur[1]-1 >=0 and cur[0]-1 >=0:
            if not visited[cur[0]-1][cur[1]-1]:
                visited[cur[0]-1][cur[1]-1] = True
                q.put(([cur[0]-1, cur[1]-1], curDist+1))

        if cur[1]-1 >= 0 and cur[0]+1 < 8:
            if not visited[cur[0]+1][cur[1]-1]:
                visited[cur[0]+1][cur[1]-1] = True
                q.put(([cur[0]+1, cur[1]-1], curDist+1))

        if cur[1]+1 <8 and cur[0]-1 >=0:
            if not visited[cur[0]-1][cur[1]+1]:
                visited[cur[0]-1][cur[1]+1] = True
                q.put(([cur[0]-1, cur[1]+1], curDist+1))