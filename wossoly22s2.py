n = int(input())

best = [i for i in range(n, 0, -1)]

print(*best)

if n <= 2:
    print(*[i for i in range(1, n+1)])
elif n == 3:
    print("1 3 2")
elif n == 4:
    print("1 3 4 2")
elif n == 5:
    print("1 3 4 5 2")
elif n == 6:
    print("1 3 4 5 6 2")
elif n == 7:
    print("1 3 4 5 6 7 2")
elif n == 8:
    print("1 3 4 5 6 7 8 2")
else:
    ans = [1] + [i for i in range(3, n+1)] + [2]
    print(*ans)