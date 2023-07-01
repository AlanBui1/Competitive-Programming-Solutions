def solve():
    cnt = 0
    pay = [5, 10, 25, 100, 200]
    lis = [int(i) for i in input().split()]
    for i in range(5):
        cnt += lis[i]*pay[i]
    print(cnt)
solve()