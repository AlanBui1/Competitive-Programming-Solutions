import sys; input = sys.stdin.readline

flag = False

n = int(input())
ans= 1
lis = []
highest = -10000000
for i in range(n):
    c = int(input())
    if c > 0:
        flag = True
        ans *= c
    elif c < 0:
        lis.append(c)

    highest = max(highest, c)

if len(lis) > 1:
    lis.sort()
    flag = True
    for i in range(len(lis)//2*2):
        ans *= lis[i]

if flag:
    print(ans)
else:
    print(highest)