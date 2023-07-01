n = int(input())
if n == 1:
    print(2)
elif n == 2:
    print(4)
elif n == 3:
    print(6)
else:
    if n%2 == 0:
        print((n//2+1)**2)
    else:
        print((n//2+1)*(n//2+2))