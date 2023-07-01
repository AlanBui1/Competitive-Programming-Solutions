def recur(cur, string, has, used):
    if cur == 0:
        print(has)
        return

    for i in range(len(string)):
        if not used[i]:
            used[i] = 1
            recur(cur-1, string, has+string[i], used)
            used[i] = 0

def solve():
    s = [i for i in input()]
    s.sort()

    recur(len(s), s, "", [0 for i in range(len(s))])

for i in range(5):
    solve()