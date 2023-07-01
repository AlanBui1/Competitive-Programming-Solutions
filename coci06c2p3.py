n1, n2 = map(int, input().split())

side = {}

lhs = [i for i in input()]
rhs = [i for i in input()]
lhs.reverse()

lis = []
for i in lhs:
    lis.append(i)
    side[i] = "left"
    
for i in rhs:
    lis.append(i)
    side[i] = "right"

t = int(input())
newlis = lis.copy()
for _ in range(t):
    for i in range(n1+n2-1):
        if side[lis[i]] == "left" and "right" == side[lis[i+1]]:
            temp = lis[i]
            newlis[i] = lis[i+1]
            newlis[i+1] = temp
    
    lis = newlis.copy()

print(*lis, sep="")