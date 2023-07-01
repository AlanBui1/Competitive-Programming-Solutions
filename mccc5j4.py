s = int(input())
line = [i for i in input()]
stars = line.count("*")

alphaSum = 0
for i in line:
    if i == "*":
        continue
    alphaSum += ord(i) - 97 + 1

smallest = stars + alphaSum
highest = stars*26 + alphaSum

if not (smallest <= s <= highest):
    print("Impossible")
else:
    ind = -1
    for i in line:
        ind += 1
        if i == "*":
            stars -= 1
            for v in range(1, 27):
                if alphaSum + v + (26*stars) >= s:
                    alphaSum += v
                    line[ind] = chr(v+97-1)
                    break

    print(*line, sep="")