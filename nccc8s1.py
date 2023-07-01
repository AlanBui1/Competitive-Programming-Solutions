alpha = input()
s = input()

ans = set()

for i in range(len(s)+1):
    ans.add(s[:i] + s[i+1: ])
    for k in alpha:
        ans.add(s[:i] +k+ s[i+1: ])
        ans.add(s[:i] +k+ s[i: ])


lis = list(ans)
lis.remove(s)
lis.sort()

for i in lis:
    print(i)