n = int(input())

top = [int(i) for i in input().split()]
bottom = [int(i) for i in input().split()]

total = 3*(top.count(1) + bottom.count(1))

for i in range(n-1):
    if top[i] == 1 and top[i+1] == 1:
        total -= 2
    if bottom[i] == 1 and bottom[i+1] == 1:
        total -= 2

for i in range(0, n, 2):
    if top[i] == 1 and bottom[i] == 1:
        total -= 2

print(total)