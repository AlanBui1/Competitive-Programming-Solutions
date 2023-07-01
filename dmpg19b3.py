def solve():
    line = input()
    lim = int(input())

    for i in range(len(line)-lim+1):
        if line[i:i+lim].count("S") == lim:
            print("Spamming")
            return

    print("All good")
solve()