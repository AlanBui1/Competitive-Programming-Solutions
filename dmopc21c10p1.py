def solve():
    vowels = "aeiou"
    cons = "knhmfr"
    line = input()
    leng = len(line)

    line += "."

    for i in range(leng):
        if line[i] in vowels:
            continue
        elif line[i] not in cons:
            print("NO")
            return
        else:
            if line[i] == "h":
                if line[i+1] in vowels and line[i+1] != "u":
                    continue
                else:
                    print("NO")
                    return
            elif line[i] == "f":
                if line[i+1] == "u":
                    continue
                else:
                    print("NO")
                    return
            elif line[i+1] not in vowels:
                print("NO")
                return

    print("YES")

                

t= int(input())
for i in range(t):
    solve()