ans = set()

def recur(cur1, cur2, lim1, lim2, str1, str2, has):
    if lim1 == 0 and lim2 == 0:
        ans.add(has)
        return

    if lim1 > 0:
        recur(cur1+1, cur2, lim1-1, lim2, str1, str2, has+str1[cur1])
    if lim2 > 0:
        recur(cur1, cur2+1, lim1, lim2-1, str1, str2, has+str2[cur2])

s, t = input().split()
recur(0, 0, len(s), len(t), s, t, "")

for i in ans:
    print(i)