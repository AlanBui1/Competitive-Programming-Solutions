n = int(input())

if n == 1:
    print(1)
elif n == 2:
    print(-1)
elif n == 3:
    print(-1)
elif n == 4:
    print(-1)
else:
    s = n
    if s%2 == 0:
        s -= 1
    lis = [1, 3]
    for i in range(s, 3, -2):
        lis.append(i)

    lis = lis + [4, 2]

    s = n
    if s%2 == 1:
        s -= 1
    for i in range(s, 4, -2):
        lis.append(i)
    print(*lis)