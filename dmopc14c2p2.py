l = int(input())
line = input()
ans = []
cur = ""
for i in range(l):
    if line[i] == "X":
        if cur != "":
            ans.append(cur)
        cur = ""

    else:
        cur += line[i]

if cur != "":
    ans.append(cur)
print(len(ans))
for i in ans:
    print(i)