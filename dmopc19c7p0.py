def solve():
    a, b, c, d = map(int, input().split())

    print((a+b)/2)
    print((a+c)/2)
    print((a+d)/2)
    print((b+c)/2)
    print((b+d)/2)
    print((c+d)/2)
    print((a+b+c)/3)
    print((a+b+d)/3)
    print((a+d+c)/3)
    print((d+b+c)/3)
    print((a+b+c+d)/4)
  
solve()