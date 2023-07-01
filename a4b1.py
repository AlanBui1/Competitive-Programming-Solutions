n = int(input())
num = []
y = 0
for i in range(0,n,1):
    x = int(input())
    num.append(x)
num.sort()
while y < n:
    print(num[y])
    y = y + 1