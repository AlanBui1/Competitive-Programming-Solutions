def solve():
    n = int(input())
    if n == 0:
        return
    if n == 1:
        lis = input().split()
        print(lis[0])
        return
    else:
        comps = []
        c = input().split()
        highest = [c[0], 2*int(c[1]) + 3*int(c[2]) + int(c[3])]
        c = input().split()
        shighest = [c[0], 2*int(c[1]) + 3*int(c[2]) + int(c[3])]

        if shighest[1] > highest[1]:
            highest, shighest = shighest, highest
        elif shighest[1] == highest[1]:
            if shighest[0] < highest[0]:
                highest, shighest = shighest, highest

        
        
        for i in range(n-2):
            c = input().split()
            comp = [c[0], 2*int(c[1]) + 3*int(c[2]) + int(c[3])]
            if comp[1] > highest[1]:
                highest, shighest = comp, highest
            elif comp[1] == highest[1] and comp[0] < highest[0]:
                highest, shighest = comp, highest
            elif comp[1] > shighest[1]:
                shighest = comp
            elif comp[1] == shighest[1] and comp[0] < shighest[0]:
                shighest = comp

        print(highest[0])
        print(shighest[0])

solve()