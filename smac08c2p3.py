n = int(input())
score = 0
factors = []
x = n

if n != 1:
    while x != 1:
        pos = False
        for i in range(2, int(n**0.5)+1):
            if x%i == 0:
                x //= i
                factors.append(i)
                pos = True
                break
                
        if not pos:
            factors.append(x)
            x = 1

    numfactors = len(factors)
    half = numfactors // 2
    fac1=1
    for i in range(half):
        fac1 *= factors[i]

    fac2=1
    for i in range(half, numfactors):
        fac2 *= factors[i]

    print(fac1, fac2)
    n = int(input())
    while n != 1:

        if n == fac1:
            factors = factors[0: half]

        else:
            factors = factors[half: ]

        numfactors = len(factors)
        half = numfactors//2

        fac1=1
        for i in range(half):
            fac1 *= factors[i]

        fac2=1
        for i in range(half, numfactors):
            fac2 *= factors[i]

        print(fac1, fac2)
        n = int(input())