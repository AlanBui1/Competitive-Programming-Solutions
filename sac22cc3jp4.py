import sys; input = sys.stdin.readline

q= int(input())

for _ in range(q):
    b1, n, b2 = map(int, input().split())
    orig = 1
    num = str(n)
    num =num[::-1]
    
    newnum = 0
    for i in num:
        newnum += orig*int(i)
        orig *= b1

    powers = []
    cur = 1
    while cur <= newnum:
        powers.append(cur)
        cur *= b2

    ans = []
    for i in range(len(powers)-1, -1, -1):
        if powers[i] <= newnum:
            ans.append(newnum//powers[i])
            newnum -= (newnum//powers[i])*powers[i]
        else:
            ans.append(0)

    print(*ans, sep="")