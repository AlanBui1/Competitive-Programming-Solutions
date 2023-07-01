n = int(input())
lis = []
x1 = 101
y1 = 101
x2 = 0
y2 = 0
for i in range(0,n,1):
    c = input()
    lis.append(c.split(','))
    if int(lis[i][0]) < x1:
        x1 = int(lis[i][0])
    if int(lis[i][1]) < y1:
        y1 = int(lis[i][1])
    if int(lis[i][0]) > x2:
        x2 = int(lis[i][0])
    if int(lis[i][1]) > y2:
        y2 = int(lis[i][1])
x1 -= 1
x1 = str(x1)
x2 += 1
x2 = str(x2)
y1 -= 1
y1 = str(y1)
y2 += 1
y2 = str(y2)
print(x1 +','+y1)
print(x2 +','+y2)