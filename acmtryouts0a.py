t = int(input())
x = 0
ans = 0
for t in range (0,t,1):
    n = int(input())
    while x < n:
        num = int(input())
        if num > ans:
            ans = num
        x = x + 1
        if x == n:
            print(ans)
            x = 0
            ans = 0
            break