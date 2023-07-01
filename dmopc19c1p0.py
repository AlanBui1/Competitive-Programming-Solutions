def solve():
    n = int(input())
    lis = [int(i) for i in input().split()]

    print(max(lis) - min(lis))
    
solve()