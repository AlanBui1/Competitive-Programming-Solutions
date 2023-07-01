import sys
input = sys.stdin.readline

def solve():
    n = int(input())
    lis = []
    
    for i in range(n):
        x, y = map(int, input().split())
        
        lis.append([x, y])
        
    dist = int(1e9)
    for i in range(n):
        for k in range(i+1, n):
            dist = min(dist, max(abs(lis[i][0]-lis[k][0]), abs(lis[i][1]-lis[k][1])))

    print(dist*dist)    
solve()