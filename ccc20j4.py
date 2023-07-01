t = input()
s = input()

for i in range(len(s)):
    x = t.find(s[i:]+s[0:i])
    if x >= 0:
        print('yes')
        break

if x < 0:
    print("no")