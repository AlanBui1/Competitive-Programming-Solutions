line1 = input()
line2 = input()

used1 = {}
used2 = {}
ans = "Is not an anagram."

for i in line1:
    if i != ' ':
        if i not in used1:
            used1[i]= 0

        used1[i]+=1
flag = True
for i in line2:
    if i != ' ':
        if i not in used1:
            flag = False
            break

        used1[i] -= 1

for i in used1:
    if used1[i] != 0:
        flag = False
        break

if flag:
    print("Is an anagram.")
else:
    print(ans)