def solve():
    n = int(input())

    if n == 3:
        print(1)
        print("__M")
    elif n == 4:
        print(2)
        print("_MM_")
    elif n == 5:
        print(2)
        print("__MM_")
    elif n == 6:
        print(2)
        print("M____M")
    else:
        ans = ["M" for i in range(n)]

        ans[1] = "_"
        for i in range(1, n):
            if ans[i-1] != "_" and ans[(i+1+n)%n] != "_":
                ans[(i+1+n)%n] = "_"
        print(ans.count("M"))
        print(*ans, sep="")
        
solve()