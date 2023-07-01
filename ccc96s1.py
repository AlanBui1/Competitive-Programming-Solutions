def solve():
    x = int(input())
    factors = set()
    for i in range(1, x):
        if x%i==0:
            factors.add(i)

    s = 0
    for i in factors:
        s += i

    if s == x:
        print(x, "is a perfect number.")
    elif s < x:
        print(x, "is a deficient number.")
    else:
        print(x, "is an abundant number.")

n = int(input())
for i in range(n):
    solve()