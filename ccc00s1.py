n = int(input())
lis = [int(input()) for i in range(3)]
cur = 0
lim = [35, 100, 10]
getBack = [30, 60, 9]
times = 0
while n > 0:
    n -= 1
    times += 1
    lis[cur] += 1
    if lis[cur] == lim[cur]:
        lis[cur] = 0
        n += getBack[cur]

    cur = (cur + 1) % 3
print("Martha plays",times,"times before going broke.")