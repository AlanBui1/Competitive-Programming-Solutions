def solve():
    n, b= map(int, input().split())
    m = 0

    lis = [int(i) for i in input().split()]

    for i in lis:
        if i > b:
            m += 1
    print("Bob wins"+ " $%.2f" %(100*((n-m)**0.5)), "at IOI!")

t = int(input())
for i in range(t):
    solve()