n= int(input())
lis = []
for i in range(n):
    a, b = map(int, input().split())
    lis.append([a, b])

s = 0
for i in range(n-1):
    s -= (lis[i][0]*lis[i+1][1])
    # print(lis[i][0],lis[i+1][1])
    s += (lis[i+1][0]*lis[i][1])
    # print(lis[i+1][0],lis[i][1])

s += lis[0][0]*lis[-1][1]
s -= lis[0][1]*lis[-1][0]
# s -= lis[]
import math
print(abs(math.ceil(abs(s/2))))