lis = [i for i in input().split()]
n = int(input())

line = [int(i) for i in input().split()]
newlis =[lis[line[i]] for i in range(n)]

print(*newlis, sep="")