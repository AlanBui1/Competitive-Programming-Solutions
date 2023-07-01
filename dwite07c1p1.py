n = int(input())
if n <= 1:
    print("not")
elif n == 2 or n == 3:
    print("prime")
else:
    if n%2 == 0 or n%3 == 0:
        print("not")
    else:
        factor = 5
        flag = 0
        while factor*factor <= n:
            if n%factor == 0:
                flag = 1
                break
            factor+=2
            
        if flag:
            print("not")
        else:
            print("prime")