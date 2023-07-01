t = int(input())
n = int(input())
lis = []
ans = 0
count= 0
for i in range(n):
    x = int(input())
    lis.append(x)
lis.sort()
while ans+lis[count] <= t:
    ans += lis[count]
    count += 1
print(count)