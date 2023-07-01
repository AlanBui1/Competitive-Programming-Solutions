import sys
input = sys.stdin.readline

def round(x):
    if x%1 >= 0.5:
        return int(x)+1
    return int(x)

m = int(input())
lis = [int(input()) for i in range(m)]

def works(x):
    perc = 100/x
    orig = 100/x
    pos = []
    while round(perc) <= 100:
        pos.append(round(perc))
        perc += orig
    
    for i in lis:
        if i not in pos:
            return False
    return True

ans = 101
for i in range(1, 101):
    if works(i):
        ans = i
        break
if ans == 101:
    print(1)
else:
    print(ans)