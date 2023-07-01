import sys
input= sys.stdin.readline

k = int(input())

lis = [1]
for i in range(33):
    lis.append(lis[i]*2)

for i in range(34):
    lis[i] -= 1

p = -1
for i in range(34):
    if lis[i] > k:
        p = lis[i-1]
        if p == 0 or p == 1:
            digits = 1
        else:
            digits = i-1
        break

k -= p

for i in range(digits-1, -1, -1):
    if k & (1 << i):
        print("7", end="")
    else:
        print("4", end = "")