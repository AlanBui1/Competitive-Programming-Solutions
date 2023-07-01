def solve():
    lis = [int(i) for i in input().split()]

    arithmetic = 1
    geometric = 1

    for i in range(8):
        if lis[i] + lis[i+2] != 2*lis[i+1]:
            arithmetic = 0

        if lis[i]*lis[i+2] != lis[i+1]**2:
            geometric = 0

    if arithmetic and geometric:
        print("both")
    elif arithmetic:
        print("arithmetic")
    elif geometric:
        print("geometric")
    else:
        print("neither")

    
        

    
n = int(input())
for i in range(n):    
    solve()