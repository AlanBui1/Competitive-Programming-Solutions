def isPrime(x):
    if x <= 1:
        return 0

    if x == 2 or x == 3:
        return 1

    if x %2 == 0 or x%3 == 0:
        return 0

    for i in range(3, int(x**0.5+1), 2):
        if x%i == 0:
            return 0

    return 1

for _ in range(5):
    n = input()
    ind = n.find("_")
    lis = []
    for i in range(10):
        if isPrime(int(n[:ind]+str(i)+n[ind+1:])):
            lis.append(i)

    if lis == []:
        print("Not possible")
    else:
        print(*lis)