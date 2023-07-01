n = int(input())
lis = [int(i) for i in input().split()]
tot = 0

for i in range(n):
    tot += lis[i]

win = False    
x = -1
cur = 0

for i in range(n):
    cur += lis[i]
    if cur == tot/2:
        x = i+1
        win = True
        break
    
if win:
    print(x)
else:
    print("Andrew is sad.")