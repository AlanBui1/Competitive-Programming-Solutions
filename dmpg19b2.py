def solve():
    lis = [int(i) for i in input().split()]
    x = [lis[i] for i in range(4)]
    x.sort()

    if sorted([lis[0], lis[2]]) == x[2:] or sorted([lis[1], lis[3]]) == x[2:]:
        print("trans")
    else:
        print("cis")
    
solve()