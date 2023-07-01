_ = int(input())

def solve(curWord, limit, ones):
    if len(curWord) == limit:
        if curWord.count("1") == ones:
            lis.append(curWord)
        return

    if curWord.count("1")+1 <= ones:
        solve(curWord+"1", limit, ones)

    solve(curWord+"0", limit, ones)

for i in range(_):
    n, k = map(int, input().split())

    print("The bit patterns are")

    lis = []

    solve("", n, k)

    for bit in lis:
        print(bit)


    if i < _-1:
        print()