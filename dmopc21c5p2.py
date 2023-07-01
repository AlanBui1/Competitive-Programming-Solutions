n = int(input())

if n == 1:
    print(1)
elif n == 2:
    print(-1)
elif n == 3:
    print(1, 3, 2)
elif n == 4:
    print(1, 3, 2, 4)
elif n == 5:
    print(4, 5, 3, 2, 1)
else:
    evens = n//2
    odds = n-evens
    
    ans = []
    cur = 1
    for i in range(odds-1):
        ans.append(cur)
        cur+=2
    if odds%2 == 0:
        ans.append(cur)

    c = 2
    for i in range(evens):
        ans.append(c)
        c+=2
    if odds%2 == 1:
        ans.append(cur)
    print(*ans)