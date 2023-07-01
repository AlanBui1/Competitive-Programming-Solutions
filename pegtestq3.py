z = int(input())
lis = []

for i in range (z):
  lis.append([int(x) for x in input().split()])

num = int(input())

for i in range(0,num,1):
    x = input()
    s = int(x.index(' '))
    x1 = int(x[0:s])
    y = int(x[s:])
    x1 -= 1
    y -= 1
    n = 0
    for i in range (z):
        n = n + lis[x1][i]
    for i in range (z):
        n = n + lis[i][y]
    print(n)