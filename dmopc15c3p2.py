n = int(input())
cake = [int(k) for k in input().split()]
c=0
num = 0
count = 0
if sum(cake) %n != 0:
    c=1
else:
    count = sum(cake)/n
    for i in range(n):
        num += abs(count - cake[i])
    
if c== 1:
    print('Impossible')
else:
    print(int(num/2))