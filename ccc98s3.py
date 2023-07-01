n = int(input())
turnRight = {"up":"right",
    "right": "down",
    "down": "left",
    "left": "up"
}

turnLeft = {"up" : "left",
    "left": "down",
    "down":"right",
    "right":"up"
}

for _ in range(n):
    x = y = 0
    facing = "up"
    while True:
        op = int(input())
        if op == 0:
            break

        if op == 1:
            d = int(input())

            if facing == "up":
                y += d
            elif facing == "down":
                y -= d
            elif facing == "right":
                x += d
            elif facing == "left":
                x -= d

        elif op == 2:
            facing = turnRight[facing]

        elif op == 3:
            facing = turnLeft[facing]

    print("Distance is", abs(x)+abs(y))
    if x == 0 == y:
        if _ < n-1:
            print()
        continue;

    want = []

    if x < 0:
        want.append("right")
    elif x > 0:
        want.append("left")
    if y > 0:
        want.append("down")
    elif y < 0:
        want.append("up")


    while len(want) > 0:
        if facing in want:
            want.remove(facing)
            if facing in "left right":
                print(1)
                print(abs(x))

            else:
                print(1)
                print(abs(y))

        if len(want) == 0:
            break
        if turnLeft[facing] in want:
            facing=  turnLeft[facing]
            print(3)

        elif turnRight[facing] in want:
            facing = turnRight[facing]
            print(2)

        else:
            while facing not in want:
                facing = turnRight[facing]
                print(2)

    if _ < n-1:
        print()