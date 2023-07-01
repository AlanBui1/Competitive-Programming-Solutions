n = int(input())
x = 10001

for i in range(n):
    y = float(input())
    x = min(x, y)
print(x)