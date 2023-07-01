a, b = map(int, input().split())
area = a*b

lis = [int(i) for i in input().split()]
for i in range(len(lis)):
    lis[i] -= area

print(*lis)