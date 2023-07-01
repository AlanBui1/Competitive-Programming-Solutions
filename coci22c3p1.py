def solve():
    n, m = map(int, input().split())
    a = [int(i) for i in input().split()]
    
    if n < m or min(a) < 4:
        print("NE")
    else:
        for i in range(m):
            a[i] -= 4
        for i in range(n-m):
            ind = a.index(max(a))
            if a[ind] < 4:
                print("NE")
                return
            a[ind] -= 4
        print("DA")
        
        
solve()