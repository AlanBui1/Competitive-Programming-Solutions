import sys; input = sys.stdin.readline

n = int(input())
order =[]
lis = []

for i in range(n):
    name, val = input().split(); val = int(val)

    lis.append(val)
    order.append([name, val])

lis.sort()
for name, val in order:
    if lis.index(val) > n/2:
        print(name, "is cute! <3")
    else:
        print(name, "is not cute. </3")