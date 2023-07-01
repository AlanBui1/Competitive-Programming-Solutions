import sys
input = sys.stdin.readline

n= int(input())
lis = [int(i) for i in input().split()]

def brotherly(s, e):
    for i in range(s+1, e+1):
        if abs(lis[i] - lis[i-1]) > 2:
            return False

    return True

def works(x):
    global n
    for i in range(n):
        if i+x-1 < n:
            if brotherly(i, i+x-1):
                return True
        else:
            break
            
    return False

for i in range(n, 0, -1):
    if works(i):
        print(i)
        break