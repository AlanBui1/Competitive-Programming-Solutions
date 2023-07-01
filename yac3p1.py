n, m, a, b = map(int, input().split())

lis = [[int(i) for i in input().split()] for k in range(m)]

cnt = 0
first = -1

for i in range(m):
    if len(lis[i]) == 1:
        cnt += 1
        if cnt > 1:
            lis[i] = [1, n]
        else:
            first = i

start = a
for i in range(m):
    if len(lis[i]) == 1:
        break
    if lis[i][0] == start:
        start = lis[i][1]
    elif lis[i][1] == start:
        start = lis[i][0]

end = b

for i in range(m-1, -1, -1):
    if len(lis[i]) == 1:
        break
    if lis[i][0] == end:
        end = lis[i][1]
    elif lis[i][1] == end:
        end = lis[i][0]


if end != start:
    lis[i] = [end, start]

else:
    cnt = 0
    ind1 = -1
    ind2 = -1
    for i in range(1, n+1):
        if i != start and i != end:
            cnt += 1
            if cnt == 1:
                ind1 = i
            if cnt == 2:
                ind2 = i
                break
                
    lis[first] = [ind1, ind2]
for i in range(m):
    print(*lis[i])