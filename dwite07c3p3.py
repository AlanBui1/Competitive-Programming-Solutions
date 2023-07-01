for q in range(5):
    maxSpace = int(input())
    numSongs = int(input())

    lis = []
    for i in range(numSongs):
        inp = input().split()
        lis.append([int(inp[1]), int(inp[2])])

    player = [0 for i in range(maxSpace+1)]

    for gain, space in lis:
        for i in range(maxSpace, 0, -1):
            if i-space >= 0:
                player[i] = max(player[i], player[i-space]+gain)

    print(player[-1])