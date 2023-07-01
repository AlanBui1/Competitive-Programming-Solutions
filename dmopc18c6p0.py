def solve():
    lis = [0]+[int(i) for i in input().split()]
    
    for i in range(1, 4):
        if lis[lis[lis[lis[lis[lis[i]]]]]] == i:
            print("NO")
            return
    
    print("YES")

solve()