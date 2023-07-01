n = int(input())
num = 0
lis = []
for i in range(n):
    spd = [int(k) for k in input().split()]
    lis.append(spd)
lis.sort()
for i in range(1,n,1):
    ans = (abs(lis[i][1] - lis[i-1][1])) / abs((lis[i][0] - lis[i-1][0]))
    if ans > num:
        num = ans
print(num)