n = int(input())

matrix = [[int(i) for i in input().split()]for k in range(n)]

if n == 1:
    print(matrix[0][0])

else:
    lis = [0 for i in range(n)]

    for i in range(n):
        for k in range(n):
            if i==k:
                continue
            lis[i] |= matrix[i][k]

    print(*lis)