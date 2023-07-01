def solve():
    line = input()

    OpenBracket = 0
    CloseBracket = 0

    for i in line:
        if i == "(":
            OpenBracket+=1
        if i == ")":
            CloseBracket += 1

        if CloseBracket > OpenBracket:
            print("NO")
            return
    if CloseBracket == OpenBracket:
        print("YES")
    else:
        print("NO")
q = int(input())

for _ in range(q):
    solve()