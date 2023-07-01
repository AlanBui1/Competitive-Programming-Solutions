from math import ceil
def solve():
    a, b, c = map(int, input().split())

    print(ceil(a/3)+ceil(b/3)+ceil(c/3))
    
solve()