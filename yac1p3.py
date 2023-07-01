n, t = map(int, input().split())

for _ in range(t):
    if n == 1:
        print(1)
        print("1 1")
    elif n == 2:
        print(2)
        x, y = map(int, input().split())
        if x == 1:
            a =2 
        else:
            a = 1
        if y ==1 :
            b =2
        else:
            b =1 
        print(a, b)
        done = input()

    elif n == 3:
        print(1)
        print("2 2")

        used = {}
        pos = [[1, 1], [3, 3], [1, 3], [3, 1]]
        for i in range(2):
            x, y = map(int, input().split())
            used[x*3+y] =1 

            for a, b in pos:
                if a*3+b not in used:
                    used[a*3+b] = 1
                    print(a, b)
                    break

        done = input()

    else:
        if n%2 == 1:
            print(1)
            print(n//2+1, n//2+1)

        else:
            print(2)

        while True:
            x, y = map(int, input().split())
            if x == 0 and y == 0:
                break

            print(n-x+1, n-y+1)