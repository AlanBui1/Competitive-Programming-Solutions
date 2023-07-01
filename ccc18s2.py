n = int(input())
lis = [[int(i) for i in input().split()] for k in range(n)]

def rotate():
    global lis
    newList = [[0 for i in range(n)] for k in range(n)]

    for i in range(n):
        for k in range(n):
            newList[i][k] = lis[n-1-k][i]

    lis = newList.copy()

def check():
    for i in range(n-1):
        if lis[0][i] >= lis[0][i+1]:
            return False
            
    for i in range(n-1):
        for k in range(n):
            if lis[i][k] > lis[i+1][k]:
                return False
        
    return True

while True:
    if check():
        for i in range(n):
            print(*lis[i])
        break
    rotate()