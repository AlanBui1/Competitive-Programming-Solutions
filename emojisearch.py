line = input()

open = 0
emoji = ""

for i in range(len(line)):
    cur = line[i]

    if cur == ":":
        if not open:
            open = 1

        else:
            open = 0
            print(emoji)
            emoji = ""

    elif open:
        emoji += cur