n= int(input())
lis = {}
for i in range(n):
    name = input()
    name = name[0]
    if name in lis:
        lis[name]+=1
        
    else:
        lis[name] = 1
        
flag = False
ans = []

for i in lis:
    if lis[i] >= 5:
        ans.append(i)
        flag = True

if not flag:
    print("PREDAJA")
else:
    ans.sort()
    print(*ans, sep="")