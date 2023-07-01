def solve():
    w, h = map(int, input().split())
    b = 0
    for i in range(h):
        line = input()

        b += line.count("o")
        line = line.replace("o", " ")
        line = line.replace("*", " ")
        line = list(line)
        for k in range(len(line), w):
            line.append(" ")
        # //print(*line)
        # print(line)
        for k in line:
            print(k, end = "")
        print()

    print("o"*b)
solve()