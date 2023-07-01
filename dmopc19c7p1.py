a, b, c, d = map(int, input().split())

electrons = (2*a) + (4*b) + (6*c) + (2*d)
H = d
if (electrons-H)%4 != 0:
   print("invalid")
else:
    C = (electrons-H)//4

    if a == 0:
        if b == 0 and c == 0:
            if H == 4:
                print("C1H4")
            else:
                print("invalid")

        else:
            if c + min(b, 0) > 0:
                print("invalid")
    elif c + min(b, 0) <= a+1 and a+b+c+d == C+H-1:
        print("C"+str(C)+"H"+str(H))
    else:
        print("invalid")