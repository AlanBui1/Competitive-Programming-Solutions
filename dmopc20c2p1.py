def solve():
    n = int(input())
    line = input()

    ans = [["." for i in range(n)] for k in range(3000)]

    cur = 1500
    highest = -1
    lowest = int(1e9)

    used = [0 for i in range(3000)]
    
    for i in range(n):
        if line[i] == "v":
            cur+=1
            ans[cur][i] = "\\"
            used[cur] = 1
        elif line[i] == "^":
            ans[cur][i] = "/"
            used[cur] = 1
            cur-=1
        else:
            ans[cur][i] = "_"
            used[cur] = 1

        highest = max(highest, cur)
        lowest = min(lowest, cur)

    for i in range(3000):
        if used[i]:
            print(*ans[i], sep="")
    
solve()