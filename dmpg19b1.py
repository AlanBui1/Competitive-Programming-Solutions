def solve():
    n = int(input())
    
    lis = [int(i) for i in input().split()]

    ppl = sum(lis)

    if ppl > 200:
        print("Over maximum capacity!")
    else:
        print(200-ppl)
solve()