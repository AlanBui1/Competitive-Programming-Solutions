w = int(input())
n = int(input())
lis = [int(input()) for i in range(n)]
p1 = 0
p2 = 0
curWeight = 0
while p1 < n and p2 < n:
    curWeight += lis[p2]
    if p2 - p1 == 4:
        curWeight -= lis[p1]
        p1 += 1
    
    if curWeight > w:
        break

    p2 += 1

print(p2)