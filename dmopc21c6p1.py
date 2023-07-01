d = int(input())
num = [int(i) for i in input()]

for i in range(d-1):
    if num[i] < num[i+1]:
        re = num[i]
        num[i] = num[i+1]
        num[i+1] = re
        break
print(*num, sep="")