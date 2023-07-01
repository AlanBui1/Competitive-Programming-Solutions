def solve():
    n, k = map(int, input().split())
    a = [int(i) for i in input().split()] 
    for i in range(n):
        if abs(a[i]-1-i) %k != 0:
            print("NO")
            return
    print("YES")
solve()