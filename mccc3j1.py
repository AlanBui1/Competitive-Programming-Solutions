n = int(input())
i = int(input())
j = int(input())

if (abs(n-(i*i)) < abs(n-(j*j))):
    print(1)
else:
    print(2)