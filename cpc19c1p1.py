n= int(input())

ans = []

p1 = 1
p2 = n

cnt = 1

while cnt <= n:
    if cnt&1:
        ans.append(p1)
        p1+=1
    else:
        ans.append(p2)
        p2-=1
    cnt +=1

print(*ans)