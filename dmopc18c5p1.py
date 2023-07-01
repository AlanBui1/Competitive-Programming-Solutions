n, m, k = map(int, input().split())

blue = 0
purple = 0

for i in range(k):
    if (n&(1 << i) and m&(1 << i)) or (not n&(1 << i) and not m&(1 << i)):
        purple += 1
    else:
        blue += 1
print(blue, purple)