n = int(input())
x, y = 0, 0

for i in range(n):
    dir = input()
    steps = int(input())

    if dir == "North":
        y += steps
    elif dir == "South":
        y -= steps
    elif dir == "East":
        x += steps
    else:
        x -= steps

print(x, y)