lis = [int(i) for i in input().split()]

while lis != [1, 2, 3, 4, 5]:
    for i in range(4):
        if lis[i] > lis[i+1]:
            temp = lis[i]
            lis[i] = lis[i+1]
            lis[1+i] = temp
            print(*lis)