from math import sqrt
n= int(input())

print("? 1 2")
n1 = int(input())
print("? 2 3")
n2 = int(input())
found = [False for i in range(n+1)]

if n == 3:
    if n1/n2 == 1/3:
        print("! 1 2 3")

    elif n1/n2 == 1/2:
        
        print("! 1 3 2")
    
    elif n1/n2 == 2/3:
        print("! 2 1 3")

    elif n1/n2 == 2:
        print("! 2 3 1")

    elif n1/n2 == 3/2:
        print("! 3 1 2")

    elif n1/n2 == 3:
        print("! 3 2 1")
else:
    v_x = n1/n2
    v__x = int(input("? 1 3\n"))
    X = int(sqrt((v__x*n2)/(n1)))
    V = v__x//X
    W = n1//V
    found[X] = 1;
    found[V] = 1;
    found[W] = 1;
    lis = [V, W, X]

    cur = 4
    for i in range(n-4):
        num = int(input("? 1 "+str(cur)+"\n"))
        lis.append(num//V)
        found[num//V] = 1
        cur+=1

    for i in range(1, n+1):
        if not found[i]:
            lis.append(i)
            break

    print("!", *lis)