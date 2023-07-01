n, m = map(int, input().split())

if m == 1:
    print("?", 1, 1)
    dist = int(input())
    p1 = [dist+1, 1]

    print("?", n, 1)
    dist = int(input())
    p2 = [n-dist, 1]

    print("!", p1[0], p1[1], p2[0], p2[1])

else:
    print("?", 1, 1)
    d1 = int(input())
    # assert(d1 >= 0)
    
    print("?", n, 1)
    d2= int(input())
    # assert(d2 >= 0)
    
    print("?", 1, m)
    d3 = int(input())
    # assert(d3 >= 0)
    print("?", n, m)
    d4 = int(input())
    # assert(d4 >= 0)

    '''
    d1 = x1 + y
    d2 = x2 + y
    d1 + d2 = N + 2y => (d1+d2-N)/2 = y
    x1 = d1 - y
    '''
    
    dists = [d1, d2, d3, d4]

    Y= (d1 + d2 - n + 1) // 2
    X = d1 - Y

    X, Y = X+1,Y+1

    print("?", max(1, X), max(1, Y))

    dist = int(input())
    assert(dist >= 0)
    if dist == 0:
        Y2 = m - ((d3 + d4 - n + 1)//2)
        X2 = n - (d4 - m + Y2)
        print("!", X, Y, X2, Y2)

    else:
        X = (d1 + d3 - m + 1) // 2
        Y = d1 - X
        X,Y = X+1, Y+1
        X2 = n - ((d2 + d4 - m + 1) //2)
        Y2 = d2 - (n - X2) + 1
        print("!", X, Y, X2, Y2)