from math import sqrt
n= int(input())
found = [False for i in range(n+1)]

if n == 4:
    x = int(input("? 1 3\n"))
    y = int(input("? 1 4\n"))
    z = int(input("? 2 4\n"))
    A = B = C = D = -1
    if x % 3 == 0:
        if y %3 == 0:
            A = 3
            C = x//3
            D = y//3
            
        else:
            C = 3
            A = x//3
            D = y//A

        found[A] = True
        found[C] = True
        found[D] = True

        lis = [A]
        for i in range(1, 5):
            if not found[i]:
                lis.append(i)
                break

        lis = lis + [C, D]
        print("!", *lis)


    elif x % 3 != 0 and y % 3 != 0:
        B = 3
        D = z//3
        A = y//D

        found[A] =True
        found[B]= True
        found[D] = True
        lis = [A, B]
        for i in range(1, 5):
            if not found[i]:
                lis.append(i)
                break

        lis = lis + [D]
        print("!", *lis)

    else:
        D = 3
        B = z//D
        A= y//D
        found[A] =True
        found[B]= True
        found[D] = True
        lis = [A, B]
        for i in range(1, 5):
            if not found[i]:
                lis.append(i)
                break

        lis = lis + [D]
        print("!", *lis)

elif n == 5:
    w = int(input("? 1 4\n"))
    x = int(input("? 2 4\n"))
    y = int(input("? 2 5\n"))
    z = int(input("? 3 5\n"))

    if w%5 == 0:
        if x%5 == 0:
            D = 5
            A = w//D
            B = x//D
            E = y//B
            C = z//E
            print("!", *[A,B,C,D,E])

        else:
            A = 5
            D = w//A
            B = x//D
            E = y//B
            C = z//E
            print("!", *[A,B,C,D,E])

    elif x%5 == 0:
        if y%5 == 0:
            B = 5
            D = x//B
            A = w//D
            E = y//B
            C = z//E
            print("!", *[A,B,C,D,E])

    elif y%5 == 0:
        E = 5
        B = y//E
        C = z//E
        D = x//B
        A = w//D
        print("!", *[A,B,C,D,E])

    else:
        C = 5
        E =z//C
        B = y//E
        D = x//B
        A = w//D
        print("!", *[A,B,C,D,E])

else:
    x = int(input("? 1 3\n"))
    y = int(input("? 1 6\n"))
    z = int(input("? 3 6\n"))
    
    F = int(sqrt(y*z/x))
    A = y//F
    C = x//A

    w = int(input("? 4 6\n"))
    D = w//F

    w = int(input("? 2 4\n"))
    B = w//D

    found[A] = found[B] = found[C] = found[D] = found[F]= True
    lis = [A,B,C,D]
    if n == 6:
        for i in range(1, 7):
            if not found[i]:
                lis.append(i)
                break

        lis.append(F)
        print("!", *lis)

    else:
        w = int(input("? 5 3\n"))
        E = w//C
        lis = [A,B,C,D,E,F]
        found[E] = True
        for i in range(7, n):
            w = int(input("? "+str(i)+" "+str(i-2)+"\n"))
            lis.append(w//lis[i-3])
            found[lis[-1]] = True

        for i in range(1, n+1):
            if not found[i]:
                lis.append(i)
                break
        print("!", *lis)