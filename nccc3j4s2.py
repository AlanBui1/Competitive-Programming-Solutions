n = int(input())
m = []
for i in range(n):
    lis = [int(k) for k in input().split()]
    m.append(sorted(lis)[int(len(lis)/2)])
print(sorted(m)[int(n/2)])