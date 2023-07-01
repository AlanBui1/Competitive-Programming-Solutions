def solve():
    year = int(input())
    if year == 0:
        print(1)
    elif year %400 == 0:
        print(1)
    elif year%100 == 0 and year%4 == 0:
        print(0)
    elif year%4 == 0:
        print(1)
    else:
        print(0)
    
t = int(input())
for i in range(t):
    solve()