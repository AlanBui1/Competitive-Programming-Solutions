def solve():
    n, m = map(int, input().split())
    ans =0
    lis = [input() for i in range(n)]
    for i in range(m):
        t = int(input())
        flag = 0
        for _ in range(t):
            name = input()
            if flag:
                continue
            if name not in lis:
                flag = 1

        if not flag:
            ans+=1

    print(ans)
solve()